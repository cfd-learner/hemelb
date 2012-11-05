# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

import pytest

import os.path
import numpy as np

from HemeLbSetupTool.Model import OutputGeneration
from HemeLbSetupTool.Model.Profile import Profile
from hemeTools.parsers.geometry.simple import ConfigLoader

class TestPolyDataGenerator:
    def test_regression(self, tmpdir):
        """Generate a gmy from a stored profile and check that the output is
        identical.
        """
        dataDir = os.path.join(os.path.split(__file__)[0], 'data')
        proFileName = os.path.join(dataDir, 'test.pro')
        
        p = Profile()
        p.LoadFromFile(proFileName)
        # Change the output to the tmpdir
        basename = tmpdir.join('test').strpath
        outGmyFileName = basename + '.gmy'
        outXmlFileName = basename + '.xml'
        p.OutputGeometryFile = outGmyFileName
        p.OutputXmlFile = outXmlFileName
        
        generator = OutputGeneration.PolyDataGenerator(p)
        generator.Execute()
        
        import filecmp
        assert filecmp.cmp(outGmyFileName, os.path.join(dataDir, 'test.gmy'))
        assert filecmp.cmp(outXmlFileName, os.path.join(dataDir, 'test.xml'))

class TestCylinderGenerator:
    
    @pytest.mark.parametrize(("randSeed",), [(828,), (341,), (1432,)])
    def test_regression(self, tmpdir, randSeed):
        """Generate a small cylinder GMY with a random orientation. Then check 
        that the output is correct by running it through a custom subclass of 
        a ConfigLoader. 
        """
        
        basename = tmpdir.join('cyl')
        OutputGeometryFile = basename.strpath + '.gmy' 
        OutputXmlFile = basename.strpath + '.xml'
        VoxelSizeMetres = 0.1
        
        rng = np.random.RandomState(randSeed)
        Axis = rng.normal(size=(3,))
        Axis /= np.sqrt(np.dot(Axis,Axis))
        
        LengthMetres = 1.32
        RadiusMetres = 0.74
        
        generator = OutputGeneration.CylinderGenerator(OutputGeometryFile, OutputXmlFile,
                                      VoxelSizeMetres, Axis, LengthMetres,
                                      RadiusMetres)
        generator.Execute()
        
        checker = CylinderTestingGmyParser(OutputGeometryFile, VoxelSizeMetres,
                                           Axis, LengthMetres, RadiusMetres)
        checker.Load()
        return
    
    pass

class CylinderTestingGmyParser(ConfigLoader):
    def __init__(self, filename, VoxelSize, Axis, Length, Radius):
        ConfigLoader.__init__(self, filename)
        self.VoxelSize = VoxelSize
        self.Axis = Axis
        self.Length = Length
        self.Radius = Radius
        return
    
    def IsInside(self, x):
        xDOTn = np.dot(x, self.Axis)
        if xDOTn < -0.5 * self.Length or xDOTn > 0.5 * self.Length:
            return False
        perp = x - xDOTn * self.Axis
        if np.dot(perp, perp) > self.Radius**2:
            return False
        
        return True
        
    def OnEndHeader(self):
        assert self.Domain.VoxelSize == self.VoxelSize
        
    def OnEndSite(self, block, site):
        if site.IsFluid:
            assert self.IsInside(site.Position)
        else:
            assert not self.IsInside(site.Position)
        return
    
    def OnEndBlock(self, bIdx, bIjk):
        self.Domain.DeleteBlock(bIdx)
        return
    
    pass

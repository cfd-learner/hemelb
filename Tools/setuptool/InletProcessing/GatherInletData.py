# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

#from HemeLbSetupTool.Model.Profile import Profile
#from HemeLbSetupTool.Model.Iolets import Inlet
#from InletPointFinder import InletPointFinder
#from SurfaceIntersectionFinder import SurfaceIntersectionPipeline
#
#def IterInletsData(profileFile):
#    """Iterator over the INLETS, returning the inlet lattice point 3D indices 
#    and the line defining the edge of the domain.
#    """
#    profile = Profile()
#    profile.LoadFromFile(profileFile)
#    
#    geometryFile = profile.OutputGeometryFile
#    surfaceFile = profile.StlFile
#    surfaceFileScale = profile.StlFileUnit.SizeInMetres
#    import pdb
#    pdb.set_trace()
#    inlets = filter(lambda io: isinstance(io, Inlet), profile.Iolets)
#    ipFinder = InletPointFinder(geometryFile)
#    inletPointIndices = ipFinder.Run()
#    
#    intersectionFinder = SurfaceIntersectionPipeline()
#    intersectionFinder.SetFileName(surfaceFile)
#    intersectionFinder.SetFileUnitLength(surfaceFileScale)
#    
#    for i, inlet in enumerate(inlets):
#        intersectionFinder.SetIolet(inlet)
#        yield inlet, inletPointIndices[i], intersectionFinder 
#    

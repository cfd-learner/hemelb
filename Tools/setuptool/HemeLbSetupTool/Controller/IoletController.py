# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

import weakref

from HemeLbSetupTool.Bindings.ObjectController import ObjectController
from HemeLbSetupTool.Controller.VectorController import HasVectorKeys
import pdb

class IoletController(HasVectorKeys, ObjectController):
    """Controller for inlets and outlets.
    
    The constructor
    """
    _instanceDict = weakref.WeakValueDictionary()
    @classmethod
    def New(cls, delegate):
        try:
            con = cls._instanceDict[delegate]
        except KeyError:
            con = cls._instanceDict[delegate] = cls(delegate)
            pass
        return con
    
    def __init__(self, delegate):
        ObjectController.__init__(self, delegate)
        
        self.DefineVectorKey("Centre")
        self.DefineVectorKey("Normal")
        self.DefineVectorKey("Pressure")
        return
    pass

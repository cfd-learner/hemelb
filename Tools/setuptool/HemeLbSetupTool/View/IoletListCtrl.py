# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

from HemeLbSetupTool.Bindings.BindableWxListCtrl import BindableWxListCtrl

class IoletListCtrl(BindableWxListCtrl):
    def __init__(self, *args, **kwargs):
        BindableWxListCtrl.__init__(self, *args, **kwargs)
        self.InsertColumn(0, "Name")
        return
    
    pass
    

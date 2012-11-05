# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

from ..Util.Observer import Observable

class EmptySelection(Observable):
    """Represent an empty selection.
    """
    def __getattr__(self, attr):
        return self
    
    pass

EmptySelection = EmptySelection()


def isNone(value):
    return (value is None) or (value is EmptySelection)

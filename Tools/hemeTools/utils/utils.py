#!/usr/bin/env python
# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 


import sys
import os
import numpy as np

def MatchCorresponding(first,second):
    count=second.shape[0]
    result=np.array([np.argwhere(first==val)[0] for val in second])
    return result

def MatchCorrespondingOld(first,second):
    count=second.shape[0]
    result = np.empty_like(first)
    
    for index in xrange(count):
        for search in xrange(count):
            if first[search] == second[index]:
                result[index] = search
                break
                
    return result
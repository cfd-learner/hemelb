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
import unittest
import numpy as np
from ..utils import *

class utilsTests(unittest.TestCase):
	def setUp(self):
		pass
	def testMatchCorresponding(self):
	    x=np.array([1,2,3,3,5])
	    y=np.array([2,3,5,5,1,])
	    result=MatchCorrespondingB(x,y)
	    self.assertSequenceEqual(list(result),[1,2,4,4,0])

if __name__ == '__main__':
	unittest.main()
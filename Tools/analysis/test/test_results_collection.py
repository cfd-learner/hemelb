#!/usr/bin/env python
# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 


import os
import unittest
import fixtures
from ..results_collection import ResultsCollection

class TestResultsCollection(unittest.TestCase):
	def setUp(self):
	    self.rc=ResultsCollection(fixtures.Results('cylinders').path,fixtures.ResultsConfig('example'))
	def test_construct(self):
		self.assertEqual(3*9,len(self.rc.results))
		
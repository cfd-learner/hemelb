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

import result
Result=result.result_model(fixtures.ResultsConfig('example'))

class TestResult(unittest.TestCase):
	def setUp(self):
	    self.rc=Result(fixtures.Results('cylinders').result_path(0))
	def test_construct(self):
		self.assertEqual(fixtures.Results('cylinders').result_path(0),self.rc.path)
	def test_name_property(self):
	    self.assertEqual('planck',self.rc.machine)
	def test_text_property(self):
	    self.assertEqual(1,self.rc.cores)
	    self.assertEqual('Release',self.rc.build_type)
	def test_xml_property(self):
	    self.assertEqual(2.19,self.rc.total)
	    self.assertEqual(1000,self.rc.steps)
	def test_property_count(self):
	    self.assertEqual(8,len(self.rc.properties))
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

import results_collection

class TestExtraction(unittest.TestCase):
  def setUp(self):
      self.rc=results_collection.ResultsCollection(fixtures.Results('cylinders').path,fixtures.ResultsConfig('optional'))
  def test_optionally_present(self):
    for result in self.rc.results:
      if result.cores==1:
        self.assertIn('banana',result.properties)
        self.assertEqual(result.banana,1)
      else:
        self.assertNotIn('banana',result.properties)
  def test_optional_definition(self):
    for result in self.rc.results:
      if result.cores==1:
        self.assertIn('apple',result.properties)
        if result.voxelsize!=6:
          pass
          # conflicting definition case,
          # behaviour not defined
        else:
          self.assertEqual(result.apple,result.cores)
      elif result.voxelsize!=6:
        self.assertIn('apple',result.properties)
        self.assertEqual(result.apple,result.voxelsize)
      else:
        self.assertNotIn('apple',result.properties)
	      
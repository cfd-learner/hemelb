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
import StringIO
from ..curate import Curation

class TestCuration(unittest.TestCase):
    def setUp(self):
        self.buff=StringIO.StringIO()
        self.rc=Curation(fixtures.Results('cylinders').path,fixtures.ResultsConfig('example'),['myprog','name'],self.buff)
    def test_construct(self):
        self.assertEqual(27,len(self.rc.filtered_results))
        self.assertEqual(self.rc.action.action,'name')
    def test_name(self):
        print self.buff.getvalue()
        self.rc.act()
        self.assertEqual(self.buff.getvalue().split('\n')[0],'cylinder_0_001_1000_3_546058666e20_planck_1')
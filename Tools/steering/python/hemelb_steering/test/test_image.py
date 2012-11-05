#!/usr/bin/env python
# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 


import unittest
import mock
import xdrlib

from hemelb_steering.image import Image

#Tests the SPARSE image model we use
class TestImage(unittest.TestCase):

    def setUp(self):
        fixture = xdrlib.Packer()
        count=0
        for y in xrange(1024):
            for x in xrange(1024):
                include = ( x % 2==0 and y % 4 == 0)
                if include:
                    count += 1
                    xfrac = x * 255 / 1024
                    yfrac=y * 255 / 1024
                    fixture.pack_int( (x * (1<<16) ) + y)
                    fixture.pack_fopaque(12, str(bytearray((xfrac, yfrac, 0, 0, yfrac, yfrac, xfrac, 0, xfrac, xfrac, 0, xfrac))))
        self.image = Image(1024, 1024, count, xdrlib.Unpacker(fixture.get_buffer()))
        
    def test_display(self):
        pass
        self.image.pil('velocity').show()
        
        
        
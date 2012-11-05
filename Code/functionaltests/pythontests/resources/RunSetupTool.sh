#!/bin/bash
# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

env PYTHONPATH=../../../../Tools/setuptool/:$PYTHONPATH ../../../../Tools/setuptool/scripts/hemelb-setup-nogui poiseuille_flow_test.pro
cp poiseuille_flow_test_master.xml poiseuille_flow_test.xml

# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

"""
Parse the configs defined in config.yml and config_user.yml
"""

import os
import yaml

path=os.path.dirname(os.path.abspath(__file__))
config=yaml.load(open(os.path.join(path, 'config.yml')))
config_user=yaml.load(open(os.path.join(path, 'config_user.yml')))

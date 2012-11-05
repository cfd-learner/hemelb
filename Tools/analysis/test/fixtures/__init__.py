# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

import os
import shutil
import yaml

fixtures_path=os.path.dirname(os.path.abspath(__file__))

class Results(object):
    def __init__(self,path):
        self.path=os.path.join(fixtures_path,'results',path)
        self.results=os.listdir(self.path)
    def result_path(self,index):
        return os.path.join(self.path,self.results[index])
        
class GraphConfig(dict):
    def __init__(self,label):
        self.update(yaml.load(open(os.path.join(fixtures_path,'graph_fixtures.yml')))[label])

class ReportConfig(dict):
    def __init__(self,label):
        self.update(yaml.load(open(os.path.join(fixtures_path,'report_fixtures.yml')))[label])
        
class ResultsConfig(dict):
    def __init__(self,label):
        self.update(yaml.load(open(os.path.join(fixtures_path,'result_config_fixtures.yml')))[label])
        
class ReportOutput(object):
    def __init__(self,label):
        self.path=os.path.join(fixtures_path,'reports','output',label)
        shutil.rmtree(self.path,ignore_errors=True)
        os.makedirs(self.path)
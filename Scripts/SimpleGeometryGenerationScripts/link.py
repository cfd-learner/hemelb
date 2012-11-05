# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

class Link(object):

    # Type of boundary crossed by a link
    no_boundary,wall,inlet,outlet=range(4)

    def __init__(self, link_type, wall_distance=0, iolet_index = 0):
        self.link_type = link_type
        
        # Distance to the boundary, as a fraction of the lattice vector
        self.wall_distance = wall_distance

        # Inlet/outlet index
        self.iolet_index=iolet_index

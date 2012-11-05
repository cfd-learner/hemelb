#!/bin/bash
# 
# Copyright (C) University College London, 2007-2012, all rights reserved.
# 
# This file is part of HemeLB and is provided to you under the terms of
# the GNU LGPL. Please see LICENSE in the top level directory for full
# details.
# 

# For debugging the C++ extension.

# Append '-g' and '-O0' to the compile flags and build the extension
# in place (i.e. $ python setup.py build_ext --inplace)
# Then treat this script just like the python executable
# (e.g. ./debug.sh scripts/hemelb-setup-nogui /path/to/profile.pro)

# Create a file break.gdb and add a series of GDB break statements.
# They will be set before execution starts.

cat > prebreak.gdb <<EOF
set breakpoint pending on
EOF

cat > run.gdb <<EOF
run $@
continue
EOF

export PYTHONPATH=$CWD:$PYTHONPATH
if [ -e break.gdb ]; then
    break="-x prebreak.gdb -x break.gdb"
fi

gdb $break -x run.gdb python

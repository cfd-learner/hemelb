// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_INDEX_H
#define HEMELBSETUPTOOL_INDEX_H

#include <exception>
#include "util/Vector3D.h"

class IndexError: public std::exception {
	virtual const char* what() const throw () {
		return "IndexError";
	}
};

typedef hemelb::util::Vector3D<int> Index;
typedef hemelb::util::Vector3D<double> Vector;

#endif // HEMELBSETUPTOOL_INDEX_H

// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_DEBUG_H
#define HEMELBSETUPTOOL_DEBUG_H

#include <iostream>

class DummyStream {
};

#ifdef DEBUG

template<typename T>
DummyStream& operator<<(DummyStream &ds, const T& val) {
	std::cout << val;
	return ds;
}
inline DummyStream& operator<<(DummyStream& ds, std::ostream& (*func) ( std::ostream& os )) {
	std::cout << std::endl;
	return ds;
}

#else

template<typename T>
DummyStream& operator<<(DummyStream &ds, const T& val) {
	return ds;
}
inline DummyStream& operator<<(DummyStream& ds, std::ostream& (*func) ( std::ostream& os )) {
	return ds;
}

#endif // DEBUG

DummyStream& Log();

#endif // HEMELBSETUPTOOL_DEBUG_H


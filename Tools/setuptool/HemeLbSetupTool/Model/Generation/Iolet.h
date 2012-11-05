// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_IOLET_H
#define HEMELBSETUPTOOL_IOLET_H

//#include <vector>
#include "Index.h"
struct Iolet {
	//  std::vector<double> Centre;
	//  std::vector<double> Normal;
	Vector Centre;
	Vector Normal;

	double Radius;
	int Id;
	bool IsInlet;
};

//typedef std::vector<Iolet> IoletVector;

#endif // HEMELBSETUPTOOL_IOLET_H

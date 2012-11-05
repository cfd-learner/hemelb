// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_CYLINDERGENERATOR_H
#define HEMELBSETUPTOOL_CYLINDERGENERATOR_H

#include "GeometryGenerator.h"

#include "Index.h"
#include "GetSet.h"
#include "Iolet.h"
#include "GenerationError.h"

class GeometryWriter;
class Site;
class BlockWriter;

struct CylinderData {
	// Cylinder parameters
	Vector Centre;
	Vector Axis;
	double Radius;
	double Length;
};

class CylinderGenerator : public GeometryGenerator {
public:
	CylinderGenerator();
	virtual ~CylinderGenerator();

	inline void SetCylinderCentre(Vector v) {
		this->Cylinder->Centre = v;
	}
	inline void SetCylinderAxis(Vector n) {
		this->Cylinder->Axis = n;
	}
	inline void SetCylinderRadius(double r) {
		this->Cylinder->Radius = r;
	}
	inline void SetCylinderLength(double l) {
		this->Cylinder->Length = l;
	}

private:
	virtual void ComputeBounds(double []) const;
	void ClassifySite(Site& site);
	CylinderData* Cylinder;
};

#endif // HEMELBSETUPTOOL_CYLINDERGENERATOR_H

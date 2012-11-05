// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_GETSET_H
#define HEMELBSETUPTOOL_GETSET_H

// Macros for Get/Set methods
#define GETTER(name, type) inline type Get##name (void) {return this->name;}
#define SETTER(name, type) inline void Set##name(type val) {this->name = val;}

#endif // HEMELBSETUPTOOL_GETSET_H

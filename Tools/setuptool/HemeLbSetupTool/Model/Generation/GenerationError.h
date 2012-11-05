// 
// Copyright (C) University College London, 2007-2012, all rights reserved.
// 
// This file is part of HemeLB and is provided to you under the terms of
// the GNU LGPL. Please see LICENSE in the top level directory for full
// details.
// 

#ifndef HEMELBSETUPTOOL_GENERATIONERROR_H
#define HEMELBSETUPTOOL_GENERATIONERROR_H
#include <exception>
#include <string>

struct GenerationError: public std::exception {
	virtual const char* what() const throw () {
		return "GenerationError";
	}
};

struct GenerationErrorMessage: public GenerationError {
	GenerationErrorMessage(const std::string errorMessage) :
		msg(errorMessage) {
	}
	~GenerationErrorMessage() throw () {
	}
	virtual const char* what() const throw () {
		return msg.c_str();
	}

	const std::string msg;
};

#endif

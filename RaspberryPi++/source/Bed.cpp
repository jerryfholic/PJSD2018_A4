/*
 * Bed.cpp
 *
 *  Created on: Dec 10, 2018
 *      Author: matthijs
 */

#include "Bed.h"

void Bed::sync() {

	file->updateDoc();
	comm->connectToServer();
}

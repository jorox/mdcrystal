/*
 * catom.h
 *
 *  Created on: May 19, 2017
 *      Author: wk234832
 */

#ifndef CATOM_H_
#define CATOM_H_

#include "../vect3.h"
#include "csystems/csystem.h"

class catom{

protected:
	vect3 coords;
	int id;
	CSystem *csym;

public:
	catom(int, double, double, double, const CSystem &);
	catom(int, Vect3, const CSystem *);

	int get_id() const; //return id

	Vect3 get_unit_coords() const; //coordinates

	Vect3 get_rspace_coords() const;

};

#endif /* CATOM_H_ */

/*
 * catom.cpp
 *
 *  Created on: May 19, 2017
 *      Author: wk234832
 */

#include "catom.h"

catom::catom(int basisTag, double x, double y, double z, const CSystem* sys = 0){
	coords = Vect3(x,y,z);
	basisId = basisTag;
	csym = sys;

}

catom::catom(int basisTag, Vect3 x, const CSystem* sys = 0){
	coords = x;
	basisId = basisTag;
	csym = sys;

}

Vect3 catom::get_rspace_coords() const {

	if (csym) {
		Vect3 tmp(coords);
		for (int i = 0; i<3; ++i){ tmp[i] *= *(csym)[i];}
		return tmp;
	}
	else{
		return Vect3(-9999,-9999,-9999);
	}

}

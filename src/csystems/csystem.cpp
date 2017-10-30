/*
 * csystem.cpp
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */


#include "csystem.h"
#include "../constants.h"
#include <stdexcept>
#include <iostream>
#include <limits>

/**
 * Construct the crystal system using three vectors
 */
CSystem::CSystem(Vect3 & p1, Vect3 & p2, Vect3 & p3,
				 std::list<CAtom>& atms){

	if ( CSystem::is_valid(p1, p2, p2) ){
		_a1 = Vect3(p1);
		_a2 = Vect3(p2);
		_a3 = Vect3(p3);
		std::iterator<CAtom> itAtom = atms.begin();
		for ( std::list<CAtom>::iterator it = atms.begin();
			  it != atms.end(); ++it ) {
			_motif.push_front(*itAtom);
		}//end adding atoms
	}
	else {
		throw invalid_csystem("vectors for crystal system are invalid.");
	}// end checking validity
}

/**
 * return number of atoms in the basis
 */
int CSystem::get_size_basis(){
	return _motif.size();
}

/**
 * return a basis atom of the system
 */
CAtom& CSystem::operator [] (int idx) const {
	while (idx < 0){ idx += _motif.size(); }
	idx = idx % _motif.size();
	std::list<CAtom>::iterator it = _motif.begin();
	std::advance(it, idx);
	return *it;
}

/**
 * return a lattice vector of the system
 *
 */
Vect3& lattice_vec(int idx) const{
	while (idx < 0) {idx += 3;}
	idx = idx % 3;
	if (idx == 0) {return _a1;}
	else{
		if (idx == 1) {return _a2;}
		else {return _a3;}
	}
}


static virtual bool CSystem::is_valid(Vect3& p1, Vect3& p2, Vect3& p3) {
	return true; //no limitations on a custom system
}

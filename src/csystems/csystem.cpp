/*
 * csystem.cpp
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */


#include "csystem.h"
#include "../constants.h"

/**
 * Construct the crystal system using three vectors
 */
CSystem::CSystem(Vect3 & p1, Vect3 & p2, Vect3 & p3){

	a1 = Vect3(p1);
	a2 = Vect3(p2);
	a3 = Vect3(p3);
}

/**
 *  Add a motif atom to the crystal system.
 *  @param p1 3 element double array 0<>1
 */
void CSystem::add_motif(int type, unsigned double xsu, unsigned double ysu, unsigned double zsu ){
	MotifAtom matom;
	matom.type = type;
	matom.xsu = xsu; matom.ysu = ysu; matom.zsu = zsu;
	motif.push_front(matom); // 0<=p1<1

}

/**
 * return number of atoms in the basis
 */
int CSystem::get_size_basis(){
	return motif.size();
}

/**
 * return a basis vector of the system
 */
Vect3* CSystem::operator [] (unsigned int idx) const {
	idx = idx%3;
	switch (idx) {
	case 0: return &a1;
	case 1: return &a2;
	case 2: return &a3;

	default: return 0;
	}
}

bool CSystem::is_primitive() const {
	if (motif.size() == 1){ return true;}
	return false;
}

catom CSystem::get_basis_atom(std::size_t bid) const {
	return motif[bid];
}


bool CSystem::same_space_group(CSystem& sys) const {
	// Need to implement a way to compare two crystal systems
	// i.e. need to find a way to show that the point group of the motif +
	//  the Bravais lattice lead to the same space group
	// For now just return true
	return true;
}

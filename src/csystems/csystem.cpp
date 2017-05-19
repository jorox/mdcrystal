/*
 * csystem.cpp
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */


#include "csystem.h"
#include "../constants.h"

CSystem::CSystem(){
	a1 = Vect3(1.0,0.0,0.0);
	a2 = Vect3(0.0,1.0,0.0);
	a3 = Vect3(0.0,0.0,1.0);
	alpha = PI_ / 2.0;
	beta = alpha;
	gamma = alpha;
	a = 0.0;
	b = 0.0;
	c = 0.0;

}

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
void CSystem::add_motif( const unsigned p[3] ){

	motif.push_front(Vect3(p[0],p[1],p[2])); // 0<=p1<1

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
Vect3 CSystem::operator [] (unsigned int idx) const {
	idx = idx%3;
	switch (idx) {
	case 0: return a1;
	case 1: return a2;
	case 2: return a3;
	}
}

bool CSystem::is_primitive() const {
	if (motif.size() == 1){ return true;}
	return false;
}

catom CSystem::get_basis_atom(std::size_t bid) const {
	return motif[bid];
}

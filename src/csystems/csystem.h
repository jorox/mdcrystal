/*
 * csystem.h
 *
 *	Abstract class representing a crystallographic system.
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */

#ifndef CSYSTEM_H_
#define CSYSTEM_H_

#include <list>
#include "../vect3.h"
#include "../catom.h"


class CSystem{
protected:
	std::list<catom> motif;
	Vect3 a1, a2, a3;

	void add_motif(int, unsigned double, unsigned double, unsigned double); // add a basis atom

public:

	CSystem(Vect3& p1, Vect3& p2, Vect3& p3);

	int get_size_basis(); //number of atoms in basis

	Vect3* operator [] (unsigned int idx) const; // return a lattice vector

	catom get_basis_atom(std::size_t ) const; // return a basis atom

	bool is_primitive() const; // is the system primitive ?

	bool same_space_group(CSystem &) const; // are the two CSystems equivelant i.e. same space group

};

#endif /* CSYSTEM_H_ */

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
#include <cmath>


class CSystem{
protected:
	std::list<catom> motif;
	Vect3 a1, a2, a3;
	void add_motif(atom &);

public:
	CSystem(); //default constructor
	CSystem(Vect3& p1, Vect3 & p2, Vect3 & p3);

	int get_size_basis(); //number of atoms in basis

	Vect3 operator [] (unsigned int idx) const; //basis atom

	catom get_basis_atom(std::size_t ) const;

	bool is_primitive() const;

};

#endif /* CSYSTEM_H_ */

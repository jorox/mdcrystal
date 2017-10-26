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

struct MotifPoint{
	int type;
	double xsu, ysu, zsu;
};

class CSystem{
protected:
	std::list<MotifPoint> motif;
	Vect3 a1, a2, a3;

	void add_motif(int, unsigned double, unsigned double, unsigned double); // add a basis atom

public:

	/// Create a CSystem
	CSystem(Vect3& p1, Vect3& p2, Vect3& p3, std::list<Vect3>& bs);

	/// Number of motif points
	int get_count_motif();

	/// Return
	Vect3* operator [] (unsigned int idx) const; // return a lattice vector

	catom get_basis_atom(std::size_t ) const; // return a basis atom

	bool is_primitive() const; // is the system primitive ?

	bool same_space_group(CSystem &) const; // are the two CSystems equivelant i.e. same space group

};

#endif /* CSYSTEM_H_ */

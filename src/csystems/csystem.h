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
#include "../../packages/tinyxml2/tinyxml2.h"
#include "../vect3.h"
#include "../aatom.h"

class CSystem
{
protected:
	std::list<AbstractAtom> _motif;
	Vect3 _a1, _a2, _a3;

public:

	/// Create a CSystem
	CSystem(Vect3& , Vect3& , Vect3& , std::list<AbstractAtom>& );

	/// Create a Csystem from xml information
    CSystem(const XMLElement&);

	/// Number of motif points
	int get_motif_count();

	/// Return a reference to a basis atom
	AbstractAtom& operator [] (unsigned int idx) const; ///< return a reference

	/// Return a reference to one lattice vector
	Vect3& lattice_vec(int idx) const;

	/// Return true if the lattice vectors are valid for this system
	static bool is_valid(Vect3& p1, Vect3& p2, Vect3& p3);

	/// Return true if the basis is primitive
	//bool is_primitive() const;

	//bool same_space_group(CSystem &) const; // are the two CSystems equivelant i.e. same space group

};

#endif /* CSYSTEM_H_ */

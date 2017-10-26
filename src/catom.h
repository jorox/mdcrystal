/**
 * \class CAtom
 *
 * \brief CAtom(id, type, x, y, z)
 *
 *  This class represents an atom in real space. The atom has an is identified by an id and a type
 *  The coordinates are in Angstroms
 *
 * \author Wassim K
 *
 * \version 0.1
 *
 * \date $Date: 2017/10/26$
 *
 */

#ifndef CATOM_H_
#define CATOM_H_

#include "../vect3.h"

class CAtom: public Vect3
{
private:
	int _type; ///< type
	int _id; ///< id

public:
	/// Create a CAtom
	catom(int, int, double, double, double);

	/// Create a CAtom
	catom(int, int, Vect3);

	/// Return the id of the atom
	inline int get_id()
	{return this->_id;}

	/// Return the type of the atom
	inline int get_type()
	{return this->_type;}

};

#endif /* CATOM_H_ */

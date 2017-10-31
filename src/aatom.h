/**
 * \class AbstractAtom
 *
 * \brief AbstractAtom(id, type, x, y, z)
 *
 *  This class represents an atom in abstract space. The atom is identified by an id and a type
 *  The coordinates are not in a specific unit
 *
 * \author Wassim K
 *
 * \version 0.1
 *
 * \date $Date: 2017/10/26$
 *
 */

#ifndef ABSTRACTATOM_H_
#define ABSTRACTATOM_H_

#include "vect3.h"

class AbstractAtom
{
private:
	int _type; ///< type
	int _id; ///< id
	Vect3 _coords; ///< coordinates

public:
	/// Create a CAtom
	AbstractAtom(int, int, double, double, double);

	/// Create a CAtom
	AbstractAtom(int, int, Vect3&);

	/// Return the type of the atom
	inline int get_type()
	{return this->_type;}

	/// Return the id of the atom
	inline int get_id()
	{return this->_id;}

};

#endif /* AbstractAtom_H_ */

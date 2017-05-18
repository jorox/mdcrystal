/*
 * csystem.h
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */

#ifndef CSYSTEM_H_
#define CSYSTEM_H_

#include <list>
#include "../vect3.h"
#include <cmath>


class CSystem{
private:
	double a,b,c;
	double alpha,beta,gamma;
	std::list<Vect3> motif;
	Vect3 a1, a2, a3;

public:
	CSystem();
	CSystem(Vect3& p1, Vect3 & p2, Vect3 & p3);
	void add_motif( const unsigned p[3] );
	int get_n_basis();
	Vect3 operator [] (std::size_t idx) const;
	bool is_primitive() const;
};

#endif /* CSYSTEM_H_ */

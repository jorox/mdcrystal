/*
 * bcc.h
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */

#ifndef BCC_H_
#define BCC_H_

#include "csystem.h"

class BCC: public CSystem {
	private:
		double a; //lattice parameter

	public:
		BCC(); //default constructor
		BCC(double a); //constructor

};

#endif /* BCC_H_ */

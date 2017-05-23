/*
 * bcc.cpp
 *
 *  Created on: May 18, 2017
 *      Author: wk234832
 */

#include "bcc.h"

BCC::BCC(double latspc=1.0){
	a1 = latspc*Vect3(1.0,0.0,0.0);
	a2 = latspc*Vect3(0.0,1.0,0.0);
	a3 = latspc*Vect3(0.0,0.0,1.0);
	a = latspc;
	BCC::add_motif(0,0.0,0.0,0.0);
	BCC::add_motif(0,0.5,0.5,0.5);

}

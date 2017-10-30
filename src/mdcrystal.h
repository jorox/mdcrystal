/*
 * mdcrystal.h
 *
 *  Created on: May 20, 2017
 *      Author: wassim
 */

#ifndef SRC_MDCRYSTAL_H_
#define SRC_MDCRYSTAL_H_

#include <list>
#include <stdio.h>
#include <iostream>

#include "vect3.h"
#include "catom.h"
#include "csystems/csystem.h"
#include "packages/tinyxml2/tinyxml2.h"

int main(int argc, char * argv){

	std::cout << "loading file = " << argv[1] << std::endl;

	tinyxml2::XMLDocument doc;
	doc.LoadFile( argv[1] );

	// get the root
	const char* ctype = doc.FirstChildElement( "crystallo" ).Attribute("type");

	std::cout << "ctype is " << crtpe;

}



#endif /* SRC_MDCRYSTAL_H_ */

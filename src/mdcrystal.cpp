
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
#include <stdlib.h>
#include <iostream>

#include "mdcrystalConfig.h"
#include "vect3.h"
#include "aatom.h"
#include "csystems/csystem.h"
#include "tinyxml2.h"

int main(int argc, char** argv){

	fprintf (stdout, "%s Version %d.%d.%d\n",
			 argv[0],
			 mdcrystal_VERSION_MAJOR,
			 mdcrystal_VERSION_MINOR,
			 mdcrystal_VERSION_PATCH);

	std::cout << "loading file = " << argv[1] << std::endl;

	tinyxml2::XMLDocument doc;
	doc.LoadFile( argv[1] );

	// get the root
	tinyxml2::XMLElement* root = doc.RootElement();
	const char* ctype = root->FirstChildElement( "crystallo" )->Attribute("type");

	std::cout << "ctype is " << ctype << std::endl;

}



#endif /* SRC_MDCRYSTAL_H_ */

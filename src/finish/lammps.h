/*
 * lammps.h
 *
 *  Created on: May 21, 2017
 *      Author: wassim
 */

#ifndef SRC_LAMMPS_H_
#define SRC_LAMMPS_H_

#include <string>
#include <stdio.h>
#include "../libs/eigen/Eigen/Dense"
#include "catom.h"

namespace lammps{
typedef Eigen::Matrix<float, 3, 3> Matrix3d;
typedef Eigen::Matrix<float, 3, 1> Vec3f;

void write_data_file(const std::string fname, const int Natoms, const int Ntypes,
		const std::list<double> & masses, const Matrix3d& mdBox, const Vec3f& origin, const std::list<catom>& atoms ){

	FILE * lmp_file = fopen (fname.c_str(),"w");
	// write the header
	// # Comment line add version of md crystal and maybe some other stuff
	//  	'Natoms' atoms
	// 		'Ntypes' atom types
	//
	// 'xlo' 'xhi' xlo xhi
	// 'ylo' 'yhi' ylo yhi
	// 'zlo' 'zhi' zlo zhi
	// 'xy' 'xz' 'yz' xy xz yz
	//
	// Masses
	//
	// 		1 'm1'
	//
	// Atoms
	//
	// 		'id' 'type' 'x' 'y' 'z'
	//

	fprintf (lmp_file, "#test dump file\n" );
	fprintf (lmp_file, "\t%d atoms\n\t%d atom types\n\n",Natoms,Ntypes);
	fprintf (lmp_file, "%1.5f %1.5f xlo xhi\n",origin[0],origin[0]+mdBox[0][0]);
	fprintf (lmp_file, "%1.5f %1.5f ylo yhi\n",origin[1],origin[1]+mdBox[1][1]);
	fprintf (lmp_file, "%1.5f %1.5f zlo zhi\n",origin[2],origin[2]+mdBox[2][2]);

	if (mdBox[1][0] != 0.0 or mdBox[2][0] != 0.0 or mdBox[2][1] != 0.0){
		fprintf (lmp_file, "%1.4f %1.4f %1.4f\n",mdBox[1][0],mdBox[2][0],mdBox[2][1]);
	}

	fprintf (lmp_file, "\nMasses\n\n\t");
	for (int itype=0; itype<Ntypes; ++itype){
		fprintf (lmp_file, "%d %1.4f ",itype+1,masses[itype]);
	}

	fprintf (lmp_file,"\n\nAtoms\n");

	for (std::list<catom>::iterator iatom=atoms.begin(); iatom != atoms.end(); ++iatom){
		fprintf(lmp_file,"\n\t%d %d %1.6f %1.6f %1.6f",iatom , iatom->get_id(),
				iatom->get_rspace_coords()[0],
				iatom->get_rspace_coords()[1],
				iatom->get_rspace_coords()[2]);
	}

}


}
#endif /* SRC_LAMMPS_H_ */

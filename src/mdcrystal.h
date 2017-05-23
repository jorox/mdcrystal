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
#include "vect3.h"
#include "../libs/eigen/Eigen/Dense"
#include "catom.h"
#include "csystems/csystem.h"
#include "bcc.h"
#include "lammps.h"

int main(){

	typedef Eigen::Matrix<double, 3, 3> Matrix3d;
	typedef Eigen::Matrix<double, 3, 1> Vec3d;

	FILE * pFile;

	std::list<int> nx = {-5, 5};
	std::list<int> ny = {-2, 2};
	std::list<int> nz = {0, 1};

	int Lx = nx[1] - nx[0];
	int Ly = ny[1] - ny[0];
	int Lz = nz[1] - nz[0];

	BCC unitCell;

	double x_spacing = 1.0;
	double y_spacing = 1.0;
	double z_spacing = 1.0;

	int Natoms = Lx * Ly * Lz * unitCell.get_size_basis();
	int Ntypes = 1;
	Matrix3d mdBox;
	mdBox << Lx*x_spacing, 0, 0,
			0, Ly*y_spacing, 0,
			0, 0, Lz*z_spacing;
	Vec3d origin;
	origin << nx[0] * x_spacing, ny[0] * y_spacing, nz[0] * z_spacing;

	std::list<catom> atoms;

	// create CSYSTEM for the the MD box
	CSystem boxCS(Vect3(Lx*x_spacing, 0, 0), Vect3(0, Ly*y_spacing, 0), Vect3(0, 0, Lz*z_spacing));


	for (int ix=nx[0]+1; ix<(nx[1]-nx[0]); ++ix){
		for (int iy=ny[0]+1; iy<(ny[1]-ny[0]); ++iy){
			for (int iz=nz[0]+1; iz<(nz[1]-nz[0]); ++iz){
				for (int ib=0; ib<unitCell.get_size_basis(); ++ib){
					atoms.push_front(catom())
				}
			}
		}
	}

}



#endif /* SRC_MDCRYSTAL_H_ */

/**************************************************************************
 *   output.h                                                             *
 *                                                                        *
 *   HFCXX                                                                *
 *                                                                        *
 *   This program is free software; you can redistribute it and/or modify *
 *   it under the terms of the GNU General Public License as published by *
 *   the Free Software Foundation, version 3                              *
 *                                                                        *
 *   This program is distributed in the hope that it will be useful, but  *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    *
 *   General Public License for more details.                             *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program; if not, write to the Free Software          *
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA            *
 *   02110-1301, USA.                                                     *
 *                                                                        *
 **************************************************************************/
 
#include "output.h"

// default constructor
Output::Output() {
	spacer = "\t";
}

/* print the version number
 * the version number is grabbed from the config.h and it generated
 * by Autotools using configure.ac 
 */
void Output::print_version() {
	std::string str = version();
	std::cout << str;
}

/* 
 * print the geometry of the molecule
 */
void Output::print_geometry(Molecule &mol) {
	std::stringstream str;
	unsigned int w = 33;

	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "*      GEOMETRY       *" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::endl;

	str	<< '|' << std::setw(10) << std::right << "----------" << std::right
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::endl;

	str	<< '|' << std::setw(10) << std::right << "Atom" << std::right
		<< '|' << std::setw(10) << std::right << "X"
		<< '|' << std::setw(10) << std::right << "Y"
		<< '|' << std::setw(10) << std::right << "Z"
		<< '|' << std::endl;

	str	<< '|' << std::setw(10) << std::right << "----------" << std::right
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::endl;

	for(unsigned int i=0; i < mol.nratoms(); i++) {
		str << std::setprecision(5);
		str
		<< '|' << std::setw(10) << std::right << mol[i].ps() << std::right
		<< '|' << std::setw(10) << std::right << mol[i].gr().getx()
		<< '|' << std::setw(10) << std::right << mol[i].gr().gety()
		<< '|' << std::setw(10) << std::right << mol[i].gr().getz()
		<< '|' << std::endl;
	}

	str	<< '|' << std::setw(10) << std::right << "----------" << std::right
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::endl;

	std::cout << str.str();
}

/*
 * print a summary of the calculation results
 */
void Output::print_summary(unsigned int iter, double en, unsigned int nrat, unsigned int nrorbs, unsigned int bss) {
	std::stringstream str;
	unsigned int w = 33;

	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "*       SUMMARY       *" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::endl;

	str << "Number of atoms: " << nrat << std::endl;
	str << "Number of orbitals: " << nrorbs << std::endl;
	str << "Number of GTOs: " << bss << std::endl;
	str << "Number of iterations: " << iter << std::endl;
	str << "Total energy [Hartree]: " << std::setprecision(10) << en << std::endl;
	str << std::endl;

	std::cout << str.str();
}

/*
 * output the total execution time of the program
 */
void Output::print_calculation_time(double time) {
	std::stringstream str;
  unsigned int w = 33;
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << "Program terminated succesfully after " << time << "ms." << std::endl;
	str << std::endl;
	std::cout << str.str();
}

/*
 * print coefficients of the occupied and unoccupied orbitals
 */
void Output::print_orbitals(const std::vector<double> &molorben, const std::vector<std::string> &orblist, const MatDoub &C, unsigned int nrelec) {
	std::stringstream str;
	unsigned int w = 33;

	unsigned int nrorbs = orblist.size();
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "*       ORBITALS      *" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::endl;

  for(unsigned int i=0; i<nrorbs; i++) {
str << '|' << std::setw(10) << std::right << "**********" << std::right
    << '|' << std::setw(10) << std::right << "**********"
    << '|' << std::setw(10) << std::right << "**********"
    << '|' << std::setw(10) << std::right << "**********"
    << '|' << std::endl;

    str << "|" << std::setw(10) << std::left << i+1
				<< "|" << std::setw(18) << std::right << std::fixed
				<< std::setprecision(10) << molorben[i] << " HT" 
				<< "|" << std::setw(10) << std::right;
    if(i < nrelec / 2) {
      str << std::setw(10) << " Occupied";
    } else {
      str << std::setw(10) << " Virtual";
    }
		str << "|" << std::endl;

str << '|' << std::setw(10) << std::right << "**********" << std::right
    << '|' << std::setw(10) << std::right << "**********"
    << '|' << std::setw(10) << std::right << "**********"
    << '|' << std::setw(10) << std::right << "**********"
    << '|' << std::endl;

    /* output occupancies */
    for(unsigned int j=0; j<nrorbs; j++) {
str << '|' << std::setw(21) << std::left << orblist[j] << std::right
    << '|' << std::setw(21) << std::right << std::setprecision(4) << std::fixed << C[j][i]
    << '|' << std::endl;
		}

		str << '|' << std::setw(10) << std::right << "----------" << std::right
    << '|' << std::setw(10) << std::right << "----------"
    << '|' << std::setw(10) << std::right << "----------"
    << '|' << std::setw(10) << std::right << "----------"
    << '|' << std::endl << std::endl;

  }

    std::cout << str.str();
}

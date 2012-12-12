#include "output.h"

Output::Output() {
	spacer = "\t";
}

void Output::printVersion() {
	std::string str = version();
	std::cout << str;
}

void Output::printGeometry(Molecule &mol) {
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
		<< '|' << std::setw(10) << std::right << mol[i].gr().x
		<< '|' << std::setw(10) << std::right << mol[i].gr().y
		<< '|' << std::setw(10) << std::right << mol[i].gr().z
		<< '|' << std::endl;
	}

	str	<< '|' << std::setw(10) << std::right << "----------" << std::right
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::setw(10) << std::right << "----------"
		<< '|' << std::endl;

	std::cout << str.str();
}

void Output::printFinal(unsigned int iter, double en, unsigned int nrat, unsigned int nrorbs, unsigned int bss) {
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

void Output::printEnd(double time) {
	std::stringstream str;
  unsigned int w = 33;
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << "Program terminated succesfully after " << time << "ms." << std::endl;
	str << std::endl;
	std::cout << str.str();
}

void Output::printOrbitals(const std::vector<double> &molorben, const std::vector<std::string> &orblist, const MatDoub &C, unsigned int nrelec) {
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

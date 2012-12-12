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

void Output::printFinal(unsigned int iter, double en, unsigned int nrat) {
	std::stringstream str;
	unsigned int w = 33;

	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "*       SUMMARY       *" << std::endl;
	str << std::setw(w) << std::right << "*                     *" << std::endl;
	str << std::setw(w) << std::right << "***********************" << std::endl;
	str << std::endl;

	str << "Number of atoms: " << nrat << std::endl;
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

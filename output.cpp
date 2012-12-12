#include "output.h"

Output::Output() {
	spacer = "     ";
}

void Output::printVersion() {
	std::string str = version();
	std::cout << str;
}

void Output::printGeometry(Molecule &mol) {
	std::stringstream str;

	str << spacer << spacer << spacer << spacer << "***********************" << std::endl;
	str << spacer << spacer << spacer << spacer << "*                     *" << std::endl;
	str << spacer << spacer << spacer << spacer << "*      GEOMETRY       *" << std::endl;
	str << spacer << spacer << spacer << spacer << "*                     *" << std::endl;
	str << spacer << spacer << spacer << spacer << "***********************" << std::endl;
	str << std::endl;

	for(unsigned int i=0; i < mol.nratoms(); i++) {
		str << std::setprecision(4);
		str << spacer << mol[i].ps() 
		<< spacer << mol[i].gr().x
		<< spacer << mol[i].gr().y
		<< spacer << mol[i].gr().z
		<< std::endl;
	}

	std::string out = str.str();
	std::cout << str.str();
}

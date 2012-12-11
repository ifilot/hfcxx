#include<iostream>
#include <iomanip>
#include <string.h>
#include "hf.h"
#include "version.h"
#include "clock.h"

int main(int argc, char *argv[]) {
	std::string filename;
	bool debug = false;

	if(argc == 1) {
		std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
		std::cout << "Please provide a valid input file" << std::endl;
		return 0;
	}
	
	if(!strcmp(argv[argc-2],"-m")) {
		debug = true;
	}
	
	if(argc > 1) {
		filename = argv[argc-1];
	}

	/* output compile information on execution */
	version();

	/* keep track of the time */
	Clock clock;

	Molecule mol;
	mol.read(filename);

	HF hf;
	hf.debug = debug;
	hf.molecule(mol);
	hf.run();

	clock.toc();
	std::cout << "Execution time: " << clock.passed() << " ms" << std::endl;

	return 0;
}

/*
 * version.h
 *
 * shows compile and version information at execution
 *
 * Author: Ivo Filot
 *
 */


#include "version.h"

void version() {
	std::string prog_name = "hfcxx";
	std::string version_number = "1.00";
	std::string author = "Ivo Filot <ivo@ivofilot.nl>";
	std::string date = __DATE__;
	std::string time = __TIME__;
	std::string compiler_version = __VERSION__;

	std::cout << "executing: " << prog_name << " version " << version_number << std::endl;
//	std::cout << "tracking number: " << compile_counter << std::endl;
	std::cout << "compiled on: " << date << " " << time << std::endl;
	std::cout << "compiler: gcc " << compiler_version << std::endl;
	std::cout << "author: " << author << std::endl;
	std::cout << std::endl;
	
}

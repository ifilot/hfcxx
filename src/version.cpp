/*
 * version.h
 *
 * shows compile and version information at execution
 *
 * Author: Ivo Filot
 *
 */


#include "version.h"

std::string version() {
	std::stringstream str;
	std::string prog_name = "hfcxx";
	std::string version_number = "1.3.3";
	std::string author = "Ivo Filot <ivo@ivofilot.nl>";
	std::string date = __DATE__;
	std::string time = __TIME__;
	std::string compiler_version = __VERSION__;

	str << "executing: " << prog_name << " version " << version_number << std::endl;
	//std::cout << "tracking number: " << compile_counter << std::endl;
	str << "compiled on: " << date << " " << time << std::endl;
	str << "compiler: gcc " << compiler_version << std::endl;
	str << "author: " << author << std::endl;
	str << std::endl;

	std::string out = str.str();
	return out;
}

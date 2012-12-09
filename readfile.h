#ifndef _READFILE_H
#define _READFILE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "strfunc.h"

class InputFile {
	private:
	std::string filename;
	std::ifstream infile;
	std::vector<std::string> lines;
	bool isOpen;

	public:
	InputFile(); /* default constructor */
	InputFile(std::string);	/* constructor taking filename as input */
	~InputFile();	/* default destructor */
	void readFile(std::vector<std::string> &);
	void dump();

	private: /* utility functions */
	void init();	/* initialization functions */
	void open(); /* open file for reading */
	void read(); /* read the file */
	void close(); /* close the file */
	void reset(); /* resets the pointer to the start of the file */
};

#endif // _READFILE_H

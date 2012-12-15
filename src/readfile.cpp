#include "readfile.h"

InputFile::InputFile() {
	this->init();
};

InputFile::InputFile(std::string in) {
	this->init();
	this->filename = in;
}

void InputFile::init() {
	isOpen = false;
}

InputFile::~InputFile() {
	this->close();
}

void InputFile::open() {
	if(!isOpen) {
		//std::cout << "Opening file" << std::endl;
		isOpen = true;
		infile.open(filename.c_str() );
	} else {
		std::cout << "Error, file already opened" << std::endl;
	}
}

void InputFile::close() {
	if(isOpen) {
		//std::cout << "Closing file" << std::endl;
		infile.close();
	}
}

void InputFile::read() {
	this->open();
	std::string line;

	if(infile.is_open() ) {
		while(infile.good() ) {
			getline(infile,line);
			lines.push_back(line);
		}
	}

	this->reset();
}

void InputFile::readFile(std::vector<std::string> &output) {
	this->read();
	output = lines;
}

void InputFile::dump() {
	unsigned int i = 0;
	for(std::vector<std::string>::iterator it = lines.begin(); 
	it != lines.end(); ++it) {
		i++;
		std::cout << i << "\t" << *it << std::endl;
	}
}

void InputFile::reset() {
	infile.seekg(0);
}

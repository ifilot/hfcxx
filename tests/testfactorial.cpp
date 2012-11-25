#include<iostream>
#include "../factorial.h"

int main() {

	for(unsigned int i=1; i<=10; i++) {
		std::cout << i << "!= " << fact(i) << std::endl;
	}

	for(unsigned int i=1; i<=5; i++) {
		std::cout << i << "!!= " << fact2(i) << std::endl;
	}

	return 0;
}

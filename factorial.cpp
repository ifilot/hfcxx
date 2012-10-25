#include "factorial.h"

double fact(const int i) {
	
	if(i < 0) {
		std::cout << "i must be larger than 0!" << std::endl;
	}

	if(i == -1 || i == 0) {
		return 1.0;
	}

	double ans=1;
	for(unsigned int j=i; j>1; j--) {
		ans *= j;
	}

	return ans;

}

double fact2(const int i) {

	if(i < -1) {
		std::cout << "i must be larger than -1!" << std::endl;
	}

	if(i == -1 || i == 0) {
		return 1.0;
	}

	double ans=1;
	for(unsigned int j=i; j>1; j-=2) {
		ans *= j;
	}

	return ans;

}

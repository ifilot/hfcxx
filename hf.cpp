#include "hf.h"

HF::HF(){} /* default constructor */

void HF::setAtoms(const std::vector<Atom> &atomsin) {
	atoms = atomsin;
}

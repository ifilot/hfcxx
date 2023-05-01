/**************************************************************************
 *   Copyright (C) 2023, Ivo Filot                                        *
 *                                                                        *
 *   HFCXX is free software:                                              *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   HFCXX is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

#include "test_molecule.h"

CPPUNIT_TEST_SUITE_REGISTRATION( TestMolecule );

void TestMolecule::setUp() {
}

void TestMolecule::tearDown() {
}

void TestMolecule::testH2() {
    Output out;

    Molecule mol;
    mol.read("h2.in");
    out.print_geometry(mol);

    /* perform HF calculation */
    HF hf;
    hf.debug = false;
    hf.molecule(mol);
    hf.run();

    double energy = hf.get_energy();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.11671432, energy, 1e-4);
}

void TestMolecule::testCH4() {
    Output out;

    Molecule mol;
    mol.read("ch4.in");
    out.print_geometry(mol);

    /* perform HF calculation */
    HF hf;
    hf.debug = false;
    hf.molecule(mol);
    hf.run();

    double energy = hf.get_energy();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-39.717589987190621, energy, 1e-4);
}

void TestMolecule::testBenzene() {
    Output out;

    Molecule mol;
    mol.read("benzene.in");
    out.print_geometry(mol);

    /* perform HF calculation */
    HF hf;
    hf.debug = false;
    hf.molecule(mol);
    hf.run();

    double energy = hf.get_energy();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-230.13033852795101, energy, 1e-4);
}

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

#ifndef _TEST_MOLECULE
#define _TEST_MOLECULE

#include <cppunit/extensions/HelperMacros.h>

#include "output.h"
#include "hf.h"
#include "molecule.h"

class TestMolecule : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( TestMolecule );
  CPPUNIT_TEST( testH2 );
  CPPUNIT_TEST( testCH4 );
  CPPUNIT_TEST( testBenzene );
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void testH2();
    void testCH4();
    void testBenzene();

private:
};

#endif  // _TEST_MOLECULE

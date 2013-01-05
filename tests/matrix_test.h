#ifndef _MATRIX_TEST_H
#define _MATRIX_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class MatrixTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( MatrixTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
};

#endif  // _MATRIX_TEST_H

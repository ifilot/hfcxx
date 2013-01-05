#include "matrix_test.h"
#include "matrix.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( MatrixTest );

void 
MatrixTest::setUp()
{
}

void 
MatrixTest::tearDown()
{
}

void 
MatrixTest::testConstructor()
{
  // Set up
  const double x1 = 1.1;
  const double y1 = 2.2;
  const double z1 = 3.3;

  const double x2 = 4.4;
  const double y2 = 5.5;
  const double z2 = 6.6;

  const double x3 = 7.7;
  const double y3 = 8.8;
  const double z3 = 9.9;

  // Process
  Matrix<double> mat(3,3,0.0);
  mat[0][0] = x1;
	mat[0][1] = y1;
	mat[0][2] = z1;
	mat[1][0] = x2;
	mat[1][1] = y2;
	mat[1][2] = z2;
	mat[2][0] = x3;
	mat[2][1] = y3;
	mat[2][2] = z3;

  // Check
  CPPUNIT_ASSERT_EQUAL( x1, mat[0][0] );
	CPPUNIT_ASSERT_EQUAL( y1, mat[0][1] );
	CPPUNIT_ASSERT_EQUAL( z1, mat[0][2] );
	CPPUNIT_ASSERT_EQUAL( x2, mat[1][0] );
	CPPUNIT_ASSERT_EQUAL( y2, mat[1][1] );
	CPPUNIT_ASSERT_EQUAL( z2, mat[1][2] );
	CPPUNIT_ASSERT_EQUAL( x3, mat[2][0] );
	CPPUNIT_ASSERT_EQUAL( y3, mat[2][1] );
	CPPUNIT_ASSERT_EQUAL( z3, mat[2][2] );
}

#include "vector_test.h"
#include "vector.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( VectorTest );

void 
VectorTest::setUp()
{
}

void 
VectorTest::tearDown()
{
}

void 
VectorTest::testConstructor()
{
  // Set up
  const double x = 1.1;
  const double y = 2.2;
  const double z = 3.3;

  // Process
  Vector3 vec(x,y,z);

  // Check
  CPPUNIT_ASSERT_EQUAL( x, vec.getx() );
  CPPUNIT_ASSERT_EQUAL( y, vec.gety() );
  CPPUNIT_ASSERT_EQUAL( z, vec.getz() );
}

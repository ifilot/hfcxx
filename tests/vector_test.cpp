#include "vector_test.h"
#include "vec3.h"
#include "func.h"

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
  Vec3 vec(x,y,z); /* test regular constructor */
	Vec3 vec2(vec); /* test copy constructor */

  // Check
  CPPUNIT_ASSERT_EQUAL( x, vec.getx() );
  CPPUNIT_ASSERT_EQUAL( y, vec.gety() );
  CPPUNIT_ASSERT_EQUAL( z, vec.getz() );
	CPPUNIT_ASSERT_EQUAL( x, vec2.getx() );
  CPPUNIT_ASSERT_EQUAL( y, vec2.gety() );
  CPPUNIT_ASSERT_EQUAL( z, vec2.getz() );
}

void 
VectorTest::testDist2Function()
{
  // Set up
  const double x1 = 1.1;
  const double y1 = 2.2;
  const double z1 = 3.3;

	const double x2 = 4.4;
  const double y2 = 5.5;
  const double z2 = 6.6;

	const double ans = 32.67;

  // Process
  Vec3 a(x1,y1,z1); /* construct */
	Vec3 b(x2,y2,z2); /* construct */

  // Check
  CPPUNIT_ASSERT_EQUAL( ans, dist2(a,b) );
}

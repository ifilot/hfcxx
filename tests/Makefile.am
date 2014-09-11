AM_CPPFLAGS = -I$(top_srcdir)/include
TESTS = vector_test matrix_test
check_PROGRAMS = $(TESTS)

# vector test program sources
vector_test_SOURCES = ../include/vector.h \
../src/vec3.cpp ../src/func.cpp \
vector_test.h vector_test.cpp unittest.cpp
# + program flags
vector_test_CXXFLAGS = $(CPPUNIT_CFLAGS)
vector_test_LDFLAGS = -Wl,--no-as-needed $(CPPUNIT_LIBS) -ldl

# vector test program sources
matrix_test_SOURCES = ../include/matrix.h \
matrix_test.h matrix_test.cpp unittest.cpp
# + program flags
matrix_test_CXXFLAGS = $(CPPUNIT_CFLAGS)
matrix_test_LDFLAGS = -Wl,--no-as-needed $(CPPUNIT_LIBS) -ldl

CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS=
LIBS=
DEBUG=-g
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp hf.cpp molecule.cpp \
  canorg.cpp matfunc.cpp eigen.cpp clock.cpp \
	version.cpp basis.cpp strfunc.cpp readfile.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hfcxx
TESTS=tests/t_matrix tests/t_cgf

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) main.cpp -o $@

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

clean:
	rm *.o; rm $(EXECUTABLE)

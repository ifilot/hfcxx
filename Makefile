CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS=
LIBS=
DEBUG= -g
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	factorial.cpp func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp ludcmp.cpp hf.cpp molecule.cpp \
  canorg.cpp matfunc.cpp main.cpp eigen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hf

all: $(EXECUTABLE) testmatrix

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

test: all
	cd test; make
	
clean:
	rm *.o; rm $(EXECUTABLE)


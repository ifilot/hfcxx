CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS=
LIBS=
DEBUG=
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	factorial.cpp func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp hf.cpp molecule.cpp \
  canorg.cpp matfunc.cpp eigen.cpp clock.cpp \
	version.cpp basis.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hf
TESTS=tests/t_matrix tests/t_cgf

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) main.cpp -o $@

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

clean:
	rm *.o; rm $(EXECUTABLE)


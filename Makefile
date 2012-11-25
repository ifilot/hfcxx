CC= g++
CFLAGS= -c -Wall
LDFLAGS=
LIBS=
DEBUG= -g
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	factorial.cpp func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp ludcmp.cpp hf.cpp molecule.cpp \
  canorg.cpp matfunc.cpp eigen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hf
TESTS=tests/t_matrix tests/t_cgf

all: $(EXECUTABLE)

test: $(TESTS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) main.cpp -o $@

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

tests/t_matrix: all
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) \
tests/testmatrix.cpp -o tests/t_matrix

tests/t_matrix: all
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) \
tests/testfactorial.cpp -o tests/t_fact

tests/t_cgf: all
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) \
tests/testcgf.cpp -o tests/t_cgf

clean:
	rm *.o; rm $(EXECUTABLE); rm $(TESTS)


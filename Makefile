CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS=
LIBS=
DEBUG= -g
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	factorial.cpp func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp ludcmp.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hf
TEST=tests/h2 tests/matrix

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(CFLAGS) main.cpp -o main.o
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) main.o -o $@

tests/h2: $(OBJECTS)
	$(CC) $(LIBS) $(CFLAGS) testh2.cpp -o testh2.o
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) testh2.o -o tests/h2

tests/matrix: vector.o testmatrix.o ludcmp.o
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) testmatrix.cpp -o testmatrix.o
	$(CC) $(LIBS) $(LDFLAGS) vector.o ludcmp.o func.o factorial.o testmatrix.o -o tests/matrix

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

test: all
	cd test; make
	
clean:
	rm *.o; rm $(EXECUTABLE)


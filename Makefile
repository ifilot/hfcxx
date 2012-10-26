CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS=
LIBS=
DEBUG= -g
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	factorial.cpp func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hf
TEST=h2

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(CFLAGS) main.cpp -o main.o
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) main.o -o $@

h2: $(OBJECTS)
	$(CC) $(LIBS) $(CFLAGS) h2.cpp -o h2.o
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) h2.o -o h2

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $< -o $@

test: all
	cd test; make
	
clean:
	rm *.o; rm $(EXECUTABLE)


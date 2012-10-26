CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS=
LIBS=
DEBUG= -g
SOURCES=main.cpp vector.cpp atom.cpp gto.cpp cgf.cpp \
	factorial.cpp func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hf

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $< -o $@

test: all
	cd test; make
	
clean:
	rm *.o; rm $(EXECUTABLE)


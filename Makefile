CC= g++
CFLAGS= -O3 -c -Wall
LDFLAGS= -static
LIBS=
DEBUG=
SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp hf.cpp molecule.cpp \
  canorg.cpp matfunc.cpp clock.cpp \
	version.cpp basis.cpp strfunc.cpp readfile.cpp \
	output.cpp eispack.cpp eigsym.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hfcxx

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) main.cpp -o $@

.cpp.o:
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

clean:
	rm *.o; rm $(EXECUTABLE)

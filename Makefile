# Makefile for hfcxx

# test operating system, do not use -static on Mac
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	LDFLAGS = -static
else
	ifeq ($(UNAME), Darwin)
		LDFLAGS =
	else
		LDFLAGS = -static
	endif
endif

# directories
ODIR=obj
SDIR=src
IDIR=include
BDIR=bin
VPATH=$(SDIR)

# compile commands and flags
CC= g++
CFLAGS= -O3 -c -Wall
LIBS= -I $(IDIR)

# source and executable files
_SOURCES=vector.cpp atom.cpp gto.cpp cgf.cpp \
	func.cpp overlap.cpp kinetic.cpp gamma.cpp \
	nuclear.cpp repulsion.cpp hf.cpp molecule.cpp \
  canorg.cpp matfunc.cpp clock.cpp \
	version.cpp basis.cpp strfunc.cpp readfile.cpp \
	output.cpp eispack.cpp eigsym.cpp
SOURCES = $(patsubst %,$(ODIR)/%,$(_SOURCES))
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(BDIR)/hfcxx

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) $(SDIR)/main.cpp -o $@

$(ODIR)/%.o: %.cpp
	$(CC) $(LIBS) $(CFLAGS) $(DEBUG) $< -o $@

clean:
	rm $(ODIR)/*.o; rm $(BDIR)/$(EXECUTABLE)

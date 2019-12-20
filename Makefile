# Alexander Stern
# acs4wq
# Makefile for CS 2150 post-lab 10
# This Makefile shows how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX	= clang++ -m64

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g

# Defines the assembler
AS	= nasm

# Defines the flags for the assembler
ASFLAGS	= -f elf64 -g

# encoder files
OFILES1	= huffmanenc.o heap.o huffNode.o vecNode.o

# decoder files
OFILES2 = huffmandec.o hNode.o

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# create both executables
all:	main main2

# compile encoder
main:	$(OFILES1)
	$(CXX) $(CXXFLAGS) $(OFILES1) -o encoder

# compile decoder
main2:	$(OFILES2)
	$(CXX) $(CXXFLAGS) $(OFILES2) -o decoder


# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program

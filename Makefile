#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: main

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
main:  simple.o complex.o 
	$(CC) $(CFLAGS) -o main main.cpp simple.o complex.o 

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
simple.o:  simple.cpp simple.h  
	$(CC) $(CFLAGS) -c simple.cpp

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
complex.o:  complex.cpp complex.h simple.h  
	$(CC) $(CFLAGS) -c complex.cpp 

clean: 
	$(RM) count *.o *~
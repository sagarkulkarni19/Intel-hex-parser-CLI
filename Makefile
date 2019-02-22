#
# This is an example Makefile for Intel-Hex-utility program.  This
# program uses both the scanner simple and a complex file.
# Typing 'make' or 'make main' will create the executable file.
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# 
CC = g++
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)

default: main
main:  simple.o complex.o 
	$(CC) $(CFLAGS) -o main main.cpp simple.o complex.o 

simple.o:  simple.cpp simple.h  
	$(CC) $(CFLAGS) -c simple.cpp

complex.o:  complex.cpp complex.h simple.h  
	$(CC) $(CFLAGS) -c complex.cpp 

clean: 
	$(RM) main *.o *~

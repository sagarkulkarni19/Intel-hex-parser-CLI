//complex.h contains all the comandline options for the inten-hex utility.
#include<string.h>
#include"simple.h"
void search(char [], char[]); 
/* 
Search if a given string is present in the given input Hex file
Input arguments : Filename and the string to be searched
Output : 
		whether string is present in file or not.
		if present, then at what byte it is present.
*/
void compare_c(char [], char []); 
/*
 compares the contents of two hex files as input and displays if the two files are equivalent
Input  arguments: Two Intel Hex format filenames
Output : 
		if content is equal
			display The files are identical
		else if contents are not equal
			display byte number at which the characters are different
 */
void verify(char []); 
/*
verifies whether the Input file is in Intel Hex file format 
Input  arguments: One Intel hex filename
Output :
		Display whether it is in Intel Hex file format or not.
			(Display if there is a checksum error)
*/
void convert(char [],char []); 
/*
Converts the records of an Intel hex file to a different set of records with a max byte count restriction and displays them
Input arguments: Intel Hex filename and max byte count
Output : Records with a set max byte count
*/
void crc(char []);
/*
Displays the 8-bit CRC of the contents(Data) of the file 
Input arguments: Filename with Intel Hex records
Output : Display CRC is binary and Hexadecimal format
*/
void convert_to_binary(char []);
/*
Convert the contents of an input Intel Hex file into a binary data
Input arguments: An Intel Hex filename
Output : Display the contents of the file converted into binary digits
*/
void convert_to_hex(char [], int);
/*
Converts the contents of a binary file into Intel Hex records with incremental addresses with max byte count given(only 16/32 bytes)
Input arguments: A binary filename and size(16/32 bytes)
Output : Display the records in Intel Hex format with given max byte count
*/
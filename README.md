# Intel-hex-parser
A command line parser for Intel Hex files used in EPROM chips with additional functionalities such as converting to binary and vice versa, changing the size of the records based on the user input, CRC code for the entire file etc., This command line utility was implemented using C with additional functionalities accessed through options.

Information about the tool:
-	The tool is written using C++ and compiled using the G++ compiler 

Steps to compile:
- make 
- ./main [options] [filname1 filename2...]

This tool can be used to perform certain tasks on Intel Hex files:
Usage: [Name_of_exe] [-c file1 file2] [-y file1] [-r file1] [-b file1] [-h file1 byte_count] [-v file1 max_byte_count] [-s file1 string]
(Name of exe in our case is output.exe)
Options:

[-c]     - Compare 2 Intel Hex Binary files based on only the contents in each file.
			     Input: [Name_of_exe -c file1 file2] 
           Output:
				      Scenario 1: The files are Identical.
              Scenario 2: The files are not identical as data at byte 'x' is different.
		
[-y]     - Calculate the Cyclic Redundancy Check of one Intel Hex Binary file.
			     Input: [Name_of_exe -y file1]
			     Output: The CRC of the file (In both Binary and Hexadecimal).

[-r]     - Verify whether a file is in Intel Hex Binary File format by going through each record and verifying whether it is in the Intel Hex Binary File format.
			     Input: [Name_of_exe -r file1]
			     Output: 
              Scenario 1: All the records are in Intel Hex Binary File format.
              Scenario 2: Record number 'x' is not in Intel Hex Binary File format.
 
[-b]	- Convert the input Intel Hex file into binary format.
			  Input: [Name_of_exe -b file1]
			   Output: The contents of the file converted to binary format. ** 

[-h]    	-      Convert the input Binary file into Intel Hex records.
			Input: [Name_of_exe -h file1 No_of_bytes]
Output: Intel Hex records with size given by Number of bytes (16 or 32 bytes) and having incremental addresses. **

[-v]	-       Convert the given Intel Hex file to another Intel Hex file with given max byte count limit.
			Input: [Name_of_exe -v file1 max_byte_count]
Output: Intel Hex records with maximum byte count provided in input. **
	[-s]	-	Search for the given string in the file.
			Input: [Name_of_exe -s file1 string]
			Output: whether string is present in file1 or not.
**NOTE: 
	When executing output.exe with [-b] or [-h] or [-v] options, the output in simply printed in the command window. These options require the user to manually redirect the standard stream (STDOUT) to a file as shown below:

-	Execute the command “output -b test.hex   >  binary.bin”
 *‘>’ directs the STDOUT stream into the specified file ‘binary.bin’.*
     -  	Execute the command “output -h binary.bin 16 > new.hex”
 *‘>’ directs the STDOUT stream into the specified file ‘new.hex’.*
     -  	Execute the command “output -v test.hex 10   > new1.hex”
 *‘>’ directs the STDOUT stream into the specified file ‘new.hex’.*

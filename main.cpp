#include <stdio.h>
#include <string.h>
#include "complex.h"
#include "simple.h"


int main(int argc, char *argv[]) // argc -> argument count and argv -> argument values
{
 	if(argc == 1)
 	{
	 		printf("\nFormat : %s [-c file1 file2 ][-y file1][-r file1][-b file1][-h file1 byte_count][-v file1 max_byte_count][-s filename string]", argv[0]);
			printf("\n\nOptions : ");
			printf("\n\n[-c] \t - \t Compare 2 Intel Hex Binary files based on contents(data) present in the file. \n");
			printf("\n\n[-y] \t - \t Calculate the Cyclic Redundancy Check of one Intel Hex Binary file. \n");
			printf("\n\n[-r] \t - \t Verify whether a file is in Intel Hex Binary File format.  \n");
			printf("\n\n[-b] \t - \t Convert the given Intel Hex file to binary format  \n");
			printf("\n\n[-h] \t - \t Convert the given binary file to Intel Hex file format(byte count given)  \n");
			printf("\n\n[-v] \t - \t Convert the given Intel Hex file to another Intel Hex file with given max byte size limit  \n");
			printf("\n\n[-s] \t - \t Check if a given string is present in the contents of the Intel Hex file  \n");
		
		return 0;  
	}
 	else
	{
		switch(get_c(argv[1]))
	    {
		  					  case 'c' :
							  	   	   	if(argc == 4) // Number of arguments must be 4 [name_of_exe -c file1 file2] (4 arguments in total)
							  	   	   	{
													compare_c(argv[2],argv[3]);
									   	 }
										else
										{
										 	printf(" \n [-c file1 file2] \n");
									 	} 		   	 
										 break;
							case 'y' :
								 	  	if(argc == 3)
									    {
											 printf("\nThe Cyclic redundancy Check of the above Intel Hex File is : ");
											 crc(argv[2]);
								    	}
										else
										{	
											printf("\nUse the correct format [-y file1] \n");
										}				  			  		 
										break;
							case 'r' :
								 	    if(argc == 3)
									    {
									   		verify(argv[2]); 
								        }
										else
										{
											printf("\nUse the correct format [-r file1] \n");
										}
									break;		 						
							case 'b' :
										if(argc == 3)
										{
											convert_to_binary(argv[2]);
										}
										else
										{
											printf("\nUse the correct format [-b file1] \n");
										}
										break;
							case 'h' :
										if(argc == 4)
										{
											if(strcmp(argv[3],"16")==0)
											convert_to_hex(argv[2],16);
											else if(strcmp(argv[3],"32")==0)
											convert_to_hex(argv[2],32);	
											else
											{
												printf("Only 16 or 32 byte format allowed");
											}
										}
										else
										{
											printf("\nUse the correct format [-h file1 byte_count] \n");
										}
										break;
							case 'v' :
										if(argc==4)
										{
											convert(argv[2],argv[3]);
										}
										else
											printf("\nUse the correct format [-v file1 max_byte_count] \n");
										break;
							case 's' : 
										if(argc==4)
										{
											search(argv[2],argv[3]);
										}
										else
											printf("\nUse the correct format [-s filename string]");
										break;
							default  : 
										printf("\nInsufficient/Incorrect  Arguments \n");	
		}
		 
	}
 	return 0;
}

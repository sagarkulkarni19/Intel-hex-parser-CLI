//simple.h contains all the simple functions used by various functions in this utility.
#include<string.h>

int checksum(int [], int size, int cs);
/*
Calculates the checksum of the Intel Hex record and compare it with the checksum already present in the record to check if there
is a check sum error.
Input arguments: Integer array of (byte count, address, record type and data) , size of the record( byte count + 4) , already present checksum in the record
 *4+byte count is sent for check sum calculation as byte count, address(2) and record type is also included in the calculation of the check sum*
Output : 
			if calculated checksum is equal to checksum in the record
				return 0
			else
				display 'Checksum error'
					return 1;					
*/
int ret_checksum(int [],int);
/*
Calculates the checksum of the Intel Hex record and return it.
Input arguments: Integer array of (byte count, address, record type and data) , size of the record( byte count + 4)  
*4+byte count is sent for check sum calculation as byte count, address(2) and record type is also included in the calculation of the check sum*
Output :
		Returns the checksum of the record	
*/
char get_c(char []); 
/*
returns character at position 1 in the character array
*/
int hex(char); 
/*
returns the decimal as an integer data type given a hexadecimal character
*/

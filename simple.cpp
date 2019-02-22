#include"simple.h"
#include<stdio.h>
char get_c(char x[]) // removes '-' from the string which represents the options 
{
 	return x[1];
}

int hex(char c) // returns the decimal values(as an integer) from the input hexadecimal character
{
 	int res =0 ;
 	if(c >= '0' && c <='9')
 	res = c - '0';
 	else if(c >= 'A' && c <= 'F')
 	res = c - 'A' + 10;

 	return res;
}

int checksum(int dat[], int size, int cs) // calculate the check_sum value of the dat[] array and compare with cs(existing checksum)
{
	int i, p1, p2, check_sum;
 	int sum =0;
 	
 	for(i=0;i<size;++i)
 	{
	 	   sum += dat[i]; 
    }
	
	p1= sum%16;  
	sum = sum/16;
	p2 = sum%16;
	check_sum = 255 - (p2*16 + p1 ) + 1; // two's complement for hexadecimal values
	p1 = check_sum %16;
	check_sum = check_sum/16;
	p2 = check_sum %16;
	check_sum = p2 * 16 + p1;
	 
		if(check_sum == cs) // if the calculated checksum and the existing check sum are equal , return 0
			return 0; 				   
 	printf("\nThe check sum is %i while in the file it is %i \n Record is corrupt \n", check_sum, cs );
 	return 1; // if the calculated checksum and the existing check sum are not equal, return 1
}

int ret_checksum(int dat[], int size) // returns the check sum of the dat[] array 
{
	int i, p1, p2,check_sum;
	int sum =0;
 	
 	for(i=0;i<size;++i)
 	{
	 	   sum += dat[i];
    }
	
	p1= sum%16;
	sum = sum/16;
	p2 = sum%16;
	check_sum = 255 - (p2*16 + p1 ) + 1;
	p1 = check_sum %16;
	check_sum = check_sum/16;
	p2 = check_sum %16;
	check_sum = p2 * 16 + p1;
	return check_sum;
}	

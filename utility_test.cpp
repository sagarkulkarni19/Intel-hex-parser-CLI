#include<stdio.h>

char get_c(char x[])
{
 	 return x[1];
 	 }

int main(int argc, char *argv[])
{
 	int x;
 	//printf("Argc value = %i ", argc);
 	if(argc == 1)
 	{
	 		printf("Usage : %s [-c file1 file2][-y file1][-r file1]", argv[0]);
		 // c -> compare the 2 hex files y -> cyclic redundancy check of 1 hex file , r-> Simply read the given hex file 
			printf("\n\n[-c] \t - \t Compare 2 Intel Hex Binary files \n");
			printf("\n\n[-y] \t - \t Calculate the Cyclic Redundancy Check of one Intel Hex Binary file \n");
			printf("\n\n[-r] \t - \t Read the Contents of one Intel Hex Binary file \n");
			return 0;  
		}
 	else{
		 switch(get_c(argv[1]))
		 {
		  					  case 'c' :
							  	   	   	if(argc == 4)
							  	   	   	{
										 		printf("\nComparing the 2 hex files");
										 		   	 }
										else
										{
										 	printf(" \n [-c file1 file2] \n");
										 	return 0;
										 	} 		   	 
										 break;
							case 'y' :
								 	  	 if(argc == 3)
											printf("\nThe Cyclic redundancy Check of the above Intel Hex File is : ");
										else
										{	
											printf("\nUse the correct format [-y file1] \n");
											return 0;
										}				  			  		 
										break;
							default : 
									printf("\nInsufficient/Incorrect  Arguments \n");				
									return 0;			 		   	 
		  					  }
		 
		 }
 	scanf("%i", &x);
 	return 0;
 	}

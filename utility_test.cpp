#include<stdio.h>
void compare(char [], char []);
struct intel_hex_record
{
 	   int size;
 	   int address;
 	   int add1;
 	   int add2;
	   int record_type;
 	   int data[256];
 	   int check_sum;
 	   
 	   void display()
 	   {
	   		int i=0;
	   		printf("\n SIZE : %02X \n ADDRESS : %04X \n RECORD TYPE : %02X \n DATA : \n ", size, address, record_type);
	   		for(i=0;i<size;++i)
	   		{
			 				   printf(" %02X ",data[i]);
	     	   }
			 printf("\n CHECK SUM : %02X", check_sum);				   
  		}
  		void print_hex_format(int i=0)
  		{
		 	 
		 	printf(":%02X%04X%02X", size, address, record_type);
			  for(;i<size;++i)
			  				  printf("%02X", data[i]);
			printf("%02X", check_sum);  				  
        }
        void print_data()
		{
		 	 int i;
		 	 for(i=0;i<size;++i)
		 	 {
			  					printf("%02X", data[i]);
			  					}
		 	 }
        
}record[100], new_record[100];

char get_c(char x[])
{
 	 return x[1];
}
int hex(char c)
{
 	int res =0 ;
 	if(c >= '0' && c <='9')
 	res = c - '0';
 	else if(c >= 'A' && c <= 'F')
 	res = c - 'A' + 10;
 	
 	
 	return res;
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
										 		compare(argv[2],argv[3]);
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
 	
 	return 0;
 	}
 	
 	
 	
 	
 	
// 
void compare(char f1[], char f2[])
{
 
 	 FILE *file1 = fopen(f1,"r");
 	
 	 int Line_Feed, c1, c2, c3, c4, i=0, j=0 ;
  	 char c;
  	 
   printf("FILE name : %s \n", f2 );
 	 while(1)
 	 {
	  		c = fgetc(file1);
			record[i].size = hex(fgetc(file1))*16 + hex(fgetc(file1));
			
			c1 = hex(fgetc(file1));
			c2 = hex(fgetc(file1));
		  	c3 = hex(fgetc(file1));
		   	c4 = hex(fgetc(file1));  			  
	  		 
 	        record[i].address = c1 * 16 * 16 * 16 + c2 * 16 * 16  + c3 * 16 + c4;  
	  		record[i].add1 = c1*16 + c2;
	  		record[i].add2 = c3*16 + c4;
	  		record[i].record_type = hex(fgetc(file1))*16 + hex(fgetc(file1));
			
				for(j=0;j<record[i].size;++j)
					{
					 		record[i].data[j] = hex(fgetc(file1)) * 16 + hex(fgetc(file1));			   	 
				    }
			record[i].check_sum = hex(fgetc(file1))*16 + hex(fgetc(file1));
			Line_Feed = fgetc(file1);	    
		/*		    printf("\n RECORD NUMBER : %i ", i+1);
	  		record[i].display();
		*/			printf("\n Regular Format : \n ");
			record[i].print_hex_format();		
			
			 i++;  
			  if(Line_Feed==0xFFFFFFFF) // (record[i-1].record_type == 1)||
			  {
			   							 //printf("\n END OF FILE ");
			   							 break;
			   }
			  
   }
   i=0;
   fclose(file1);
    FILE *file2 = fopen(f2,"r");
   printf("\nFILE name : %s \n", f2 );
    while(1)
 	 {
	  		c = fgetc(file2);
			new_record[i].size = hex(fgetc(file2))*16 + hex(fgetc(file2));
			
			c1 = hex(fgetc(file2));
			c2 = hex(fgetc(file2));
		  	c3 = hex(fgetc(file2));
		   	c4 = hex(fgetc(file2));  			  
	  		 
 	        new_record[i].address = c1 * 16 * 16 * 16 + c2 * 16 * 16  + c3 * 16 + c4;  
	  		new_record[i].add1 = c1*16 + c2;
	  		new_record[i].add2 = c3*16 + c4;
	  		new_record[i].record_type = hex(fgetc(file2))*16 + hex(fgetc(file2));
			
				for(j=0;j<new_record[i].size;++j)
					{
					 		new_record[i].data[j] = hex(fgetc(file2)) * 16 + hex(fgetc(file2));			   	 
				    }
			new_record[i].check_sum = hex(fgetc(file2))*16 + hex(fgetc(file2));
			Line_Feed = fgetc(file2);	    
		/*		    printf("\n RECORD NUMBER : %i ", i+1);
	  		record[i].display();
			*/		printf("\n Regular Format : \n ");
			new_record[i].print_hex_format();		
			
			 i++;  
			  if(Line_Feed==0xFFFFFFFF) // (record[i-1].record_type == 1)||
			  {
			   							 //printf("\n END OF FILE ");
			   							 break;
			   }
			  
   }
    	
}	

#include<stdio.h>
void compare(char [], char []);
struct dat
{
 	   int size;
 	   int address;
 	   int data[1000];
 	   
 	   void display()
 	   {
	   		int i;
	   		printf("\nThe address is : %04X \n Size = %02X \n DATA : \n", address, size);
	   		for(i=0;i<size;++i)
	   		{
			 				   printf("%02X", data[i]);
			 				   }
			 				   printf("\n");
	   		}
 	   
 	   }one[100], two[100];
struct intel_hex_record
{
 	   int size;
 	   int address;
 	   int add1;// used for check sum
 	   int add2;// used for check sum 
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
										 	//	printf("\nComparing the 2 hex files");
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
  	 
  // printf("FILE name : %s \n", f2 );
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
		*/	//		printf("\n Regular Format : \n ");
		//	record[i].print_hex_format();		
			
			 i++;  
			  if(Line_Feed==0xFFFFFFFF) // (record[i-1].record_type == 1)||
			  {
			   							 //printf("\n END OF FILE ");
			   							 break;
			   }
			  
   }
   int rec_file1 = i;
   i=0;
   fclose(file1);
    FILE *file2 = fopen(f2,"r");
  // printf("\nFILE name : %s \n", f2 );
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
			*/	//	printf("\n Regular Format : \n ");
		//	new_record[i].print_hex_format();		
			
			 i++;  
			  if(Line_Feed==0xFFFFFFFF) // (record[i-1].record_type == 1)||
			  {
			   							 //printf("\n END OF FILE ");
			   							 break;
			   }
			   
			  
   }
   int rec_file2 = i;
  
   int k=0, l=0;
   for(i=0;i<rec_file1;++i)
   {
   						   j=i+1;
   						   
							  if(record[i].address == -1)
   						   continue;
   						   
   						   one[k].address = record[i].address;
   						   
							  for(l=0;l<record[i].size;++l)
   						   {
						   								one[k].data[l] = record[i].data[l];
						   								}
						   	int f = l;							
   						   while(j<rec_file1)
   						   {
						   					 if(record[i].address == record[j].address)
						   					 {
											  					  for(l=0;l<record[j].size;++l)
											  					  {
																   				one[k].data[f++] = record[j].data[l];			   
										   							   }
											  				record[j].address = -1;
															 	  
											
						  					  }
						  					  
												j++;
											
											  					  
			   					 }
			   					 
				 				              one[k].size = f;
						  				//	  one[k].display();
					  					  	  k++;
   }
   int size_one = k;
   k=0;
   l=0;
   // printf("\nNumber of record for file 2 : %i \n", rec_file2);
      for(i=0;i<rec_file2;++i)
   {
   						   j=i+1;
   						   
							  if(new_record[i].address == -1)
   						   continue;
   						   
   						   two[k].address = new_record[i].address;
   						   
							  for(l=0;l<new_record[i].size;++l)
   						   {
						   								two[k].data[l] = new_record[i].data[l];
						   								}
						   	int f = l;							
   						   while(j<rec_file2)
   						   {
						   					 if(new_record[i].address == new_record[j].address)
						   					 {
											  					  for(l=0;l<new_record[j].size;++l)
											  					  {
																   				two[k].data[f++] = new_record[j].data[l];			   
										   							   }
											  				new_record[j].address = -1;
															 	  
											
						  					  }
						  					  
												j++;
											
											  					  
			   					 }
			   					 
				 				              two[k].size = f;
						  				//	  two[k].display();
					  					  	  k++;
   }
   int size_two = k;
   int flag = 0;
   int m =0;
  
   for(i=0;i<size_one;++i)
   {
   						 for(j=0;j<size_two;++j)
   						 {
						  						if(one[i].address == two[j].address)
						  						{
												 	if(one[i].size == two[j].size)
													 {
													  			  for(m = 0;m< one[i].size;++m)
																	{
																	 	if(one[i].data[m] == two[j].data[m])
																		 continue;
																		 else
																		 {
																		  	 flag = -1;
																		  	 break;
																		  	 }	
																	} 
																	break;
													   }
													   else
													   {
									   	   			   	   flag = -3;
									   	   			   	   break;
													   	   }			  
												  }
												 
						  						if(flag==-1)
						  						break;
	  						}
	  						if(flag<0)
	  						break;
		 }
		 if(flag == -1)
		 {
		  		 printf("The files are not identical \n At Address : %04X \n Byte number : %i", one[i].address, m );
		  		 }
		  else if(size_one!=size_two)
		  {
		   		  printf("The files are not identical \nThe number of addresses are different in both files ", one[i].address);
		   		  }		 
		  else if(flag == -3)
		   {
		   		   printf("The files are not identical \n The size of the record at Address %04X is not the same\n Size At file 1 : %02X \nSize at file 2 : %02X ",one[i].address, one[i].size, two[j].size);
		   		   }		  
		  else
		  {
		   	  printf("The files are identical");
		   	  }		 
   
   
    	
}	

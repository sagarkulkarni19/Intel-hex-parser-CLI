#include<stdio.h>

int flag =0;

struct student
{
 	   int stud_number;
 	   char name[100];
 	   int age;
 	   }s[100];

int hex(char c)
{
 	int res =0 ;
 	if(c >= '0' && c <='9')
 	res = c - '0';
 	else if(c >= 'A' && c <= 'F')
 	res = c - 'A' + 10;
 	else
 	flag = 1; 
 	
 	return res;
 	}
int checksum(int dat[], int size, int cs)
{
 	int sum =0;
 	int i;
 	for(i=0;i<size;++i)
 	{
	 				   sum += dat[i];
	 				   }
	//printf("Func - checksum - value of sum = %i", sum); 				   
	int p1,p2;
	p1= sum%16;
	sum = sum/16;
	p2 = sum%16;
	
	int check_sum = 255 - (p2*16 + p1 ) + 1;
	p1 = check_sum %16;
	check_sum = check_sum/16;
	p2 = check_sum %16;
	 check_sum = p2 * 16 + p1;
	 
	 if(check_sum == cs)
	 return 0; 				   
 	
 	printf("\nThe check sum is %i while in the file it is %i \n Record is corrupt \n", check_sum, cs );
 	
 	return 1;
 	} 	
int main()
{
    char filename[10][100];
 	int n, j;
 	printf("\n Enter the number of files to be read  :  ");
 	scanf("%i", &n);
 	for(j=0;j<n;++j)
 	{
		   printf(" \n Enter file %i     :  ", j+1);
	 				scanf("%s", &filename[j]);
	 				}
	int j1=0;
	printf("\n\n");

	
	int data[256];
	int check[267]; // (max data size) + 11(header length + check sum)
	char c;
	int c1, c2, c3, c4, i;
	int bc, rt, cs, lf, cr ; // byte count and record type and check sum, line feed and carriage return
	int add, rec_num=0;
	int stud_num =1;
	while(j1<n){
			   
			   
	FILE *nf = fopen(filename[j1], "r");
	 	j1++;
       while(flag==0)
       {
			   		c = fgetc(nf);
			   		
					   if(c!=':')
			   		{
					 	flag = 1;
						 break;	  
			 		}
 		
					 bc = hex(fgetc(nf)) * 16 + hex(fgetc(nf));
					check[0] = bc; 	
					 if(flag == 1)
		 			 break;	
					
				 	c1 = hex(fgetc(nf));
				 	c2 = hex(fgetc(nf));
				  	c3 = hex(fgetc(nf));
				   	c4 = hex(fgetc(nf));
					check[1] = c1*16 + c2;
					check[2] = c3*16 + c4;
				//	printf(" %i %i %i %i ", c1, c2, c3, c4);
					add = c1 * 16 * 16 * 16 + c2 * 16 * 16  + c3 * 16 + c4;
					
				//	printf(" %i %04X", add, add);
					if(flag == 1)
					break;
					
					rt = hex(fgetc(nf))*16 + hex(fgetc(nf));
					
					check[3] = rt;
					
					if(rt>=6||rt<0)
					flag=1;
					
					if(flag == 1)
					break;
					
					for(j=0;j<bc;++j)
					{
					 		data[j] = hex(fgetc(nf)) * 16 + hex(fgetc(nf));	
							   check[4+j] = data[j];	 
				    }
					
					cs = hex(fgetc(nf))*16 + hex(fgetc(nf));
					
					if(flag!=1)
					{
					 	printf("\nRecord number : %i  \n  ", rec_num +1);	   
					   printf("Start byte  -  %c \n Byte Count - dec: %i hex: %02X \n Address -  dec: %i hex: %04X \n Record Type - dec: %i hex: %02X \n  ", c, bc,bc,add,add,rt, rt);
        			   printf("\nDATA : \n");
        			  
         			  				 for(j=0;j<bc;++j)
     							 			 {
					 						    printf(" %02X ", data[j]);
					 						  
	  										 }
	  						if(bc==11)// It is a student record only if the byte count is 11 i.e., 10 byte for name and 1 byte for age;
							  {
							   		  s[stud_num - 1].stud_number = stud_num;
							   		  for(i=0;i<10;++i)
							   		  {
									   				   s[stud_num -1].name[i] = data[i];
									   				 //  printf("\n\n NAME char_num %i \ndata %i \ncharacter %c  \nstored %c\n", i, data[i], (char)data[i], s[stud_num -1].name[i] );
									   				   
									   				   if((char)data[i]=='\0')
									   				   break;
									   }
								   s[stud_num - 1].age = data[10]; 
							   	  printf(" \n STUDENT RECORD NUMBER : %i \n Student Name : %s \n Student age : %i",s[stud_num -1].stud_number, s[stud_num -1].name, s[stud_num -1].age);	  
							   	   	 stud_num++;
							   	   	 
						   		  }				 
						printf("\n Check sum  =  %02X", cs);
						
						
	                //  cr = fgetc(nf);
					//  printf("Carriage Return %02X", cr);
					
					
					if(rt==1)
					printf("\nThis is the last record as Record type = 01 \n\n");
					
					int size = 4 + bc;
				int cs_verify = checksum(check,size,cs);
				
			//	printf("CS_Verify = %i", cs_verify);
				
				if(cs_verify == 0)
				printf("\nCheck sum verified");
				else
				{printf("\nCheck sum error, the record is corrupt \n");flag=1; break;}
				
					  lf = fgetc(nf);
					  
					  if(lf==0xFFFFFFFF)
					  {
  					       printf("\n End of File reached \n");
					   				break;
									   	}
					  else
					  printf("\n Line Feed %02X \n\n", lf);
					  rec_num++;
					  } 
					 else
					 break;
					  int k;
					  for(k=0;k<256;++k)
					  check[k]=0;
					  
					  if(rt==1)
					  {
					   		   printf("\nEnd of file reached");
					  break;
					  }
				  
					 
   		} 
   		
		if(flag == 1)
		{
		 		printf("\nThe current record : %i is not an Intel Hex Record ", rec_num + 1);	 		
	    }
		else
		{
			printf("\n All the records were in Intel Hex format \n Interpreted(if applicable) as  ( NAME = first 10 byte and AGE = next 1 byte ) \n\n"); 				   	
		}
		flag=0;
		rec_num = 0;
}

 	getch();
}

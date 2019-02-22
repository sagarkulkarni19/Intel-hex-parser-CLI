#include<iostream>
using namespace std;
int bin_data[8000];
void returnbin(int x[], int size)
{
 	 int ans[1000][8];
 	 int x1 =0;
 	  int n, j, i, k;
 for( k=0;k<size;++k)
 {
 	 for( i=0;i<8;++i)
	 {
	  	if(x[k]%2==0)
		  {
		   	   ans[k][7-i]= 0;
		   	   
		  }	 
	 	 else
		 	 ans[k][7-i] = 1;
		
		
		x[k] = x[k]/2;	    
	 }
	 for(n=0;n<8;++n)
	 {
	  				 bin_data[x1++] = ans[k][n];
	  				 }
 }

	 cout<<"\nThe values in binary are : \n";
	 for( n=0;n<size;++n)
	 {
	 for( j=0;j<8;++j)
	 {
	  		 cout<<ans[n][j]<<" ";
	 }
	 cout<<"\n";
	 }
	 cout<<"\nThe other values in binary are \n";
	 for( n=1;n<=x1;++n)
	 {	 
	  		 cout<<bin_data[n-1]<<" ";
	  		
	 }
	 for(i=0;i<8;++i)
	 {
	  				 bin_data[x1+i] = 0;
	  				 }
	 int poly[] = {1,0,0,1,1,0,0,0,1}; 
	 
	 int crc[8];
	 
	 for(i=0;i<8;++i)
	 crc[i] = bin_data[i];
	 
	 for(i=0;i<x1;++i)
	 {
	  				  
	  				
	  	if(crc[0]==1)
		  {
		   			 for(j=0;j<8;++j)
		   			 {
					  				 if(j+1 != 8)
					  				 crc[j] = crc[j +1]^poly[j+1];
					  				 else
					  				 crc[j] = bin_data[i+j+1]^poly[j+1];
					  				 }
					  				 
		  }
		 else
		 {
		  	 for(j=0;j<8;++j)
		  	 {
			  				 if(j+1 !=8)
			  				 crc[j] = crc[j+1];
			  				 else
			  				 crc[j] = bin_data[i+j+1];
			  				 
			  				 }
			 } 
		   cout<<"\nThe CRC after iteration "<<i<<" is :  ";
	 for(k=0;k<8;++k)
	 cout<<crc[k]<<" ";	
	 cout<<"\n";	
	  					
	 }
	 cout<<"\nThe CRC is :";
	 for(i=0;i<8;++i)
	 cout<<crc[i]<<" ";
}
int main()
{
 	int x[100], n;
 	cout<<"Enter the size of the array ";
 	cin>>n;
 	for(int i=0;i<n;++i)
 	{
	 		cin>> x[i];
    }
 	returnbin(x, n);
 	
 	cin>>n;
}

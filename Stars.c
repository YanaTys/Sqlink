#include<stdio.h>

void func1(int num)
{ 
	int col=0,row=0;
	for(row=0;row<num;row++)
	{col=0;
		for(col=0;col<=row;col++)
		{
			printf("*");
		}
		printf("\n");
	}
return;
}

void func2(int num)
{ 
	int col=0,row=0;
	for(row=0;row<num;row++)
	{
                col=0;
         
		for(col=0;col<=row;col++)
		{
			printf("*");
		}
		printf("\n");

	}
for(row=num-1;row>0;row--)
	{
                col=num-1;
         
		for(col=num-1;col>num-row-1;col--)
		{
			printf("*");
		}
		printf("\n");


	}
return;
}

void func3(int num)
{ 
	int col=0,row=0,i,j;
	for(row=0,i=0;row<num;i+=2,row++)
	{
         j=row;
		for(col=0;col<=i;col++)
		{  while(j<num)
			{
				printf(" ");
                                j++;
			}
                        
 			
		   printf("*");
		}
		
		printf("\n");
	}
return;
}
int main()
{ 
	int num;
	printf("Enter number\n");
	scanf("%d",&num);
	func1(num);
	func2(num);
        func3(num);
return 0;
}

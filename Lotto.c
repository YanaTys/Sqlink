#include <stdio.h>
#include <stdlib.h>
void Lotto(int * ,int);
int main()
{  	int tempRand=0,flag=0;
     	int i=0,j=0;
        int arr[6];
	srand (time(NULL));
	while(i<6)

	{    flag=0; 
              tempRand=rand()%49+1;
		for(j=0;j<i;j++)
		{
		if(tempRand==arr[j])
                 flag=1;
		}
		if(flag==0)
                	{arr[i]=tempRand;
			i++;}

	}
	for(i=0;i<6;i++)
	{
		printf("%d\n",arr[i]);
	}
        Lotto(arr,6);

}

void Lotto(int* arr,int size)
{  	
     	int row=0,col=0,i=0;
        char arr2[5][10];
	for(row=0;row<5;row++)
		{
			for(col=1;col<=10;col++)
			{
			arr2[row][col]='-';	
			}
		}
	for(i=0;i<6;i++)
	{if(arr[i]%10==0)
		 {
		 col=arr[i]%10;
		 row=arr[i]/10%10-1;
		 }
	else {col=arr[i]%10;	
	row=arr[i]/10%10;}
	arr2[row][col]='+';

	}
	
	for(row=0;row<5;row++)
		{
			for(col=1;col<=10;col++)
			{
				printf("%c ",arr2[row][col]);
			}
			printf("\n");
		}
	return;
		
	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "da.h"


int main()
{	int cap=0;
	int num=0;
	int suc=1;
	DA_T * da;
	printf("Enter a cap\n");
	scanf("%d",&cap);
	da=createDA(cap);
	while(num!=-5)
	{
		printf("Enter an integer or -5 to end\n");
		scanf("%d",&num);
		if(num!=-5)
		{
			suc=insert( da,num);	
		}
		if(suc==0)
		{
			printf("realloc not sucsses\n");
			break;	
		}
		
	}
	printDA(da);
	destroyDA(da);
	
	
	return 0;
}

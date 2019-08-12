#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "da.h"
DA_T* createDA(int cap)
{
	DA_T* da;
	da=malloc(sizeof(DA_T));
	if(da == NULL)
	{
		return NULL;
	}
	da->cap=cap;
	da->index=0;
	da->ip=malloc(sizeof(int)*cap);
	if(da->ip == NULL)
	{
		free(da);
		return NULL;
	}
	return da;
}


int insert(DA_T* da,int num)
{
	int* temp;
	if(da != NULL)
		{
		temp=da->ip;
		if((da->index)==(da->cap))
		{
			temp=realloc(da->ip,((da->cap)*2)*sizeof(int));
			if(temp!=NULL)

			{	da->ip=temp;
				(da->cap)*=2;
			}
		
			else 
			{
				return 0;
			}
		}
		da->ip[(da->index)]=num;
		(da->index)++;
		return 1;
	}
return 0;
}
void printDA(DA_T* da)
{
int i=0;
	if(da != NULL)
	{
		for(i=0;i<da->index;i++)
		{
		printf("%d ",da->ip[i]);	
		}
	}
}
void destroyDA(DA_T* da)
{ 
	if(da!= NULL)
	{
		free(da->ip);
		free(da);
	}
}




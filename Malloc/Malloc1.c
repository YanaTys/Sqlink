#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* insert(int,int* ,int *,int* );

int main()
{	int cap=0,i=0,j=0;
	int num=0;
	int*ip;
	printf("Enter a cap\n");
	scanf("%d",&cap);
	ip=(int*)malloc(cap*sizeof(int));
	while(num!=-5)
	{
		printf("Enter an integer or -5 to end\n");
		scanf("%d",&num);
		if(num!=-5)
		{
			insert(num,ip,&i,&cap);
			
		}
		
	}
	for(j=0;j<cap;j++)
	{
		printf("%d",ip[j]);
	}
	return 0;
}

int* insert(int num,int*ip,int *index,int* cap)
{	int* temp;
	if((*index)<(*cap))
	{
		ip[(*index)]=num;
		(*index)++;
	}

	else 
	{
		temp=realloc(ip,((*cap)+1)*sizeof(int));
		if(temp!=NULL)

		{	ip=temp;
			ip[(*index)]=num;
			(*index)++;
			(*cap)++;
		}
	}
return ip;

}

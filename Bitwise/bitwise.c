#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitwise.h"

static void ItoB(  int num)
{
int i=num/2;

char arr[100];
if (num==0)
{
	arr[0]='0';
	arr[1]='\0';
}
for(i=0;i<32;i++)
{
	arr[i]=num%2+'0';
	num=num/2;
}
arr[i]='\0';
for(i=strlen(arr)-1;i>=0;i--)
{
	printf("%c",arr[i]);

}
return;
}



bitMap_t* createBitMap(int nf)
{	int i,size;
	bitMap_t* bm=malloc(sizeof(bitMap_t));
	if(bm ==NULL)
		return NULL;
	size=(nf%32>0?nf/32+1:nf/32);
	bm->m_bitArr=calloc(size,sizeof(int));
	if(bm->m_bitArr ==NULL)
		{free(bm);
		return NULL;}
	bm->m_nf=nf;
	
	return bm;	
}

void printBitMap(bitMap_t* bm)
{	int i,size,num;
	
	size=(bm->m_nf%32>0?bm->m_nf/32+1:bm->m_nf/32);
	if(bm !=NULL)
	{	printf("nf=%d\n",bm->m_nf);
		
		for(i=0;i<size;i++)
		{	num=((int)bm->m_bitArr[i]);
			ItoB(num);
			
		}
		printf("\n");
	}
	return;
}



int bitOn(bitMap_t* bm,int n)
{	int i,index;
	int num=1;
	if(n>bm->m_nf)
		return -1;
	i=(n%32>0?n/32+1:n/32);
	index=n%32>0?n%32:32;	
	num<<=(index-1);	
	bm->m_bitArr[i]=bm->m_bitArr[i]|num;
	return 1;
}

int bitOff(bitMap_t* bm,int n)
{	int i,index;
	int num=1;
	if(n>bm->m_nf)
		return -1;
	i=(n%32>0?n/32+1:n/32);
	index=n%32>0?n%32:32;	
	num<<=index-1;
	num=~num;	
	bm->m_bitArr[i]=bm->m_bitArr[i]&num;
	return 1;
}
int bitStatus(bitMap_t* bm,int n)
{
	int i,index;
	int num=1;
	if(n>bm->m_nf)
		return -1;
	i=(n%32>0?n/32+1:n/32);
	index=n%32>0?n%32:32;	
	num<<=index-1;	
	num=bm->m_bitArr[i]&num;
	if(num==0)
		return 0;
	else 	
		return 1;
}

void destroyBitMap(bitMap_t* bm)
{
	if (bm!=NULL)
	{
		free(bm->m_bitArr);
		free(bm);
	}	
}



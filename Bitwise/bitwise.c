#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitwise.h"
static void ItoB( unsigned  int num);



bitMap_t* createBitMap(int nf)
{	int i;
	bitMap_t* bm=malloc(sizeof(bitMap_t));
	if(bm ==NULL)
		return NULL;
	bm->m_bitArr=calloc((nf%8>0?nf/8+1:nf/8),sizeof(char));
	if(bm->m_bitArr ==NULL)
		{free(bm);
		return NULL;}
	/*for(i=0;i<(nf%8>0?nf/8+1:nf/8);i++)
	{
		bm->m_bitArr[i]='0';
	}*/
	bm->m_nf=nf;
	
	return bm;	
}

void printBitMap(bitMap_t* bm)
{	int i;
	if(bm !=NULL)
	{	printf("nf=%d\n",bm->m_nf);
		for(i=0;i<(bm->m_nf%8>0?bm->m_nf/8+1:bm->m_nf/8);i++)
		{	
			ItoB((bm->m_bitArr[i])-'0');
			
		}
		printf("\n");
	}
	return;
}



int bitOn(bitMap_t* bm,int n)
{	int i,index;
	unsigned char num=1;
	if(n>bm->m_nf)
		return -1;
	i=(n%8>0?n/8+1:n/8);
	index=n%8>0?n%8:8;	
	num=num<<(index-1);	
	bm->m_bitArr[i]=bm->m_bitArr[i]|num;
	return 1;
}

int bitOff(bitMap_t* bm,int n)
{	int i,index;
	unsigned char num=1;
	if(n>bm->m_nf)
		return -1;
	i=(n%8>0?n/8+1:n/8);
	index=n%8>0?n%8:8;	
	num<<=index-1;
	num=~num;	
	bm->m_bitArr[i]=bm->m_bitArr[i]&num;
	return 1;
}
int bitStatus(bitMap_t* bm,int n)
{
	int i,index;
	unsigned char num=1;
	if(n>bm->m_nf)
		return -1;
	i=(n%8>0?n/8+1:n/8);
	index=n%8>0?n%8:8;	
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

static void ItoB( unsigned  int num)
{
int i=num/2;

char arr[100];
if (num==0)
{
	arr[0]='0';
	arr[1]='\0';
}
for(i=0;num>0;i++)
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

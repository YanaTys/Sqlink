#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bitwise2.h"

static void ItoB( unsigned int num)
{
int i=0,j=0;

char arr[256];
if (num==0)
{
	arr[0]='0';
	arr[1]='\0';
}
while(num>0)
{
	arr[i]=num%2+'0';
	num=num/2;
	i++;
}
arr[i]='\0';
for(i=8;i>=0;i--)
{	if(i<=strlen(arr))
		printf("%c",arr[i]);
	else 
		printf("%c",'0');
}
return;
}

int myCompliment(unsigned char* ch)
{ unsigned char ch2=0;
if(ch !=NULL)
	{ch2=~ch2;
	*ch=*ch^ch2;
	ItoB(*ch);
	return 1;}
return -1;
}

int rotateShift(unsigned char* ch,int n)
{ unsigned char ch2=0;
if(ch !=NULL)
	{ch2=*ch;
	ch2<<=8-n;
	*ch>>=n;
	*ch=*ch|ch2;
	ItoB((unsigned int) *ch);
	return 1;}
return -1;
}
int setBits(unsigned char* ch,int p,int n,unsigned char* ch2)
{unsigned char temp =pow(2,n)-1;
if(ch!=NULL&&ch2!=NULL)
	{temp<<=(p-n);
	temp=~temp;
	*ch=*ch&temp;
	*ch2<<=8-n;
	*ch2>>=8-p;
	*ch=*ch|*ch2;
	ItoB((unsigned int) *ch);
	return 1;}
return 0;
}

int setBits2(unsigned char* ch,int i,int j,int value)
{unsigned char temp =pow(2,j-i+1)-1;
if(ch!=NULL)
	{temp<<=(i-1);	
	if(value==0)
		{temp=~temp;
		*ch=*ch&temp;}
	else
		*ch=*ch|temp;
	ItoB((unsigned int) *ch);
	return 1;}
return 0;
}	

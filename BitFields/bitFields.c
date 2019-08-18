#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitFields.h"
void ItoB( unsigned int num)
{
int i=0,j=0;

char arr[256];

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

int transTo4Bits(char* chArr)
{	int i ,count=1,len=0,size;
	if(chArr!=NULL)

		{len=strlen(chArr);
		 chArr[0]-='a';
		 chArr[0]<<=4;
		for(i=1;i<len;i++)
		{	
			if(i%2==1)
				{chArr[i]-='a';
				chArr[i-count]=chArr[i-count]|chArr[i];
				chArr[i]<<=8;}
			else
				{chArr[i]-='a';
				chArr[i-count]=chArr[i-count]|chArr[i];
				chArr[i-count]<<=4;
				chArr[i]<<=8;
				count ++;
				}
		}
		size=len%2==0?len/2:len/2+1;
		for(i=0;i<size;i++)	
			{ItoB((unsigned int)chArr[i]);
			
			}
		return len;
		
	}
	return 0;
}


int transTo4Bits2(char* chArr)
{	int i,j=0 ,count=1,len=0,size;
	un Union;
	if(chArr!=NULL)

		{len=strlen(chArr);
		
		for(i=0;i<len;i++,j+=2)
		{	Union.lr.left=chArr[j]-'a';
			
			if(j+1>=len)
				{Union.lr.right=0;
				chArr[i]=Union.c;
				break;}
			Union.lr.right=chArr[j+1]-'a';
			chArr[i]=Union.c;
			
		}
		size=len%2==0?len/2:len/2+1;
		for(i=0;i<size;i++)	
			{
			ItoB((unsigned int)chArr[i]);
			
			}
		return len;
		
	}
	return 0;
}

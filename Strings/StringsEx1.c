#include <stdio.h>
#include <string.h>
#include <math.h>

void ItoB( unsigned  int );
int BtoI(char*);

int main()

{ unsigned  int num=0;
char binarr[10]; 
printf("Enter int \n");
scanf("%u",&num);
ItoB(num);
printf("Print string 0 or 1\n");
scanf("%s",binarr);
printf("num=%d\n",BtoI(binarr));
}


void ItoB( unsigned  int num)
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
printf("\n");
return;
}


int BtoI( char* binarr)
{
int i=0,num=0,j=strlen(binarr)-1;

for(i=strlen(binarr)-1;i>=0;i--)
{
num=num+(pow(2,(j-i))*(binarr[i]-'0'));
}
return num;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilesEx.h"


int main()
{ 
	char fname[100];
	int num;
	printf("Enter file name\n");
	scanf("%s",fname);
	counWord(fname);
	printf("Enter file name\n");
	scanf("%s",fname);
	counChr(fname);
	printf("Enter file name\n");
	scanf("%s",fname);
	printf("Enter num\n");
	scanf("%d",&num);
	lastNlines(num,fname);



	return 0;
}

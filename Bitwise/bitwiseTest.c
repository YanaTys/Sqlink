#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitwise.h"

int main()
{
	int nf,n,funcNum;
	bitMap_t*  bm;
	bitsFunc bf[3]= {bitOn,bitOff,bitStatus};
	printf("Enter number of fitures\n");
	scanf("%d",&nf);
	bm=createBitMap(nf);
	do
	{
		printf("Enter place of bit (from 1) \n");
		scanf("%d",&n);
		if(n!=-1)
		{	printf("Enter funcNum\n0-bitOn\n1-bitOff\n2 bitStatus\n");
			scanf("%d",&funcNum);
			printf("%d\n",bf[funcNum](bm,n));
			printBitMap(bm);
		}
	}
	while(n!=-1);
	
	destroyBitMap(bm);
	
	
	
}

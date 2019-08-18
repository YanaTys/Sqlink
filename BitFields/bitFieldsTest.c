#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitFields.h"

int main()
{	char str[256];
	printf("Enter string\n");
	scanf("%s",str);
	/*printf("\nsize=%d\n",transTo4Bits(str));*/
	printf("\nsize=%d\n",transTo4Bits2(str));
	return 0;
}


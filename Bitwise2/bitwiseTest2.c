#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitwise2.h"

int main()
{unsigned char ch=170,ch2=167,x=170,y=167;
	int n,p,i,j,value,func;
	while(func!=-1)
	{
		printf("Enter function number\n1 to myCompliment\n2 rotateShift\n3 setBits\n4 setBits2\n-1 to exit\n");
		scanf("%d",&func);
		switch(func)
		{	case 1:
			printf("Enter char\n");
			scanf("%c",&ch);
			myCompliment(&ch);break;
			case 2:
			/*printf("Enter char\n");
			scanf("%c",&ch);*/
			printf("Enter n\n");
			scanf("%d",&n);
			rotateShift(&ch,n);break;
			case 3:
			/*printf("\nEnter x\n");
			scanf("%c",&x);
			printf("\nEnter y\n");
			scanf("%c",&y);*/
			printf("Enter p\n");
			scanf("%d",&p);
			printf("Enter n\n");
			scanf("%d",&n);
			setBits(&x,p,n,&y);break;
			case 4:
			/*printf("\nEnter x\n");
			scanf("%c",&x);*/
			printf("Enter i\n");
			scanf("%d",&i);
			printf("Enter j\n");
			scanf("%d",&j);
			printf("Enter value\n");
			scanf("%d",&value);
			setBits2(&x,i,j,value);break;
			 default: break;
		}
	}
	return 0;
}


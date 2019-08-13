#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diaryf.h"


int main()
{	int cap=0,choose=0;
	float begin;
	Calendar_t1* ca;
	Meeting_t* me;
	int suc=1;
	printf("Enter a cap\n");
	scanf("%d",&cap);
	ca=createAD(cap);
	while(choose!=-1)
	{	
		printf("Enter 1 to create meeting\n2 to insert\n3 to remove\n4 to find\n5 to print\n6 to load file\n7 to write diry in file\n-1 to end\n");
			scanf("%d",&choose);
		switch(choose){
			case 1: me=CreateMeeting();
			break;
			case 2: suc=insert(ca,me);
			if(suc==0)
			{	
				printf("can't insert\n");
			}
			break;
			case 3:
			printf("Enter begin\n");
			scanf("%f",&begin);
			suc=Remove(ca,begin);
			break;
			case 4:
			printf("Enter begin\n");
			scanf("%f",&begin);
			me=find(ca,begin);
			if(me==NULL)
			{	
				printf("can't find\n");
			}
			break;
			case 5:
			printAD(ca);break;
			case 6:
			loadFromFile(ca);
                        break;
			case 7:
			savePrintF(ca);
			default: break;
			}
		}

	destroyAD(ca);
	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diary.h"


int main()
{	int cap=0,choose=0;
	float begin;
	Calendar_t1* ca;
	Meeting_t* me;
	int suc=1;
	printf("Enter a cap\n");
	scanf("%d",&cap);
	while(choose!=-1)
	{	
		printf("Enter 1 to create diary\n2 to create meeting\n3 to insert\n4 to remove\n5 to find\n6 to print\n-1 to end\n");
			scanf("%d",&choose);
		switch(choose){
			case 1: ca=createAD(cap);
			break; 
			case 2: me=CreateMeeting();
			break;
			case 3: suc=insert(ca,me);
			if(suc==0)
			{	
				printf("can't insert\n");
			}
			break;
			case 4:
			printf("Enter begin\n");
			scanf("%f",&begin);
			suc=Remove(ca,begin);
			break;
			case 5:
			printf("Enter begin\n");
			scanf("%f",&begin);
			me=find(ca,begin);
			if(me==NULL)
			{	
				printf("can't find\n");
			}
			break;
			case 6:
			printAD(ca);break;
			default: break;
			}
		}

	destroyAD(ca);
	
	
	return 0;
}

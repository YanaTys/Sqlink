#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diary.h"

Calendar_t1* createAD(int cap)
{
	Calendar_t1* ca;
	ca=malloc(sizeof(Calendar_t1));
	if(ca == NULL)
	{
		return NULL;
	}
	ca->cap=cap;
	ca->index=0;
	ca->day=malloc(sizeof(Meeting_t*)*cap);
	if(ca->day == NULL)
	{
		free(ca);
		return NULL;
	}
	return ca;
}

Meeting_t* CreateMeeting()
{
	Meeting_t* me;
	float begin;
	float end;
	int room;
	me=malloc(sizeof(Meeting_t));
	if(me == NULL)
	{
		return NULL;
	}
	do
        {
		printf("Enter begin of meeting\n");
		scanf("%f",&begin);
		

	 	printf("Enter end of meeting\n");
		scanf("%f",&end);
	}while(begin>=end||end>24||begin>24||end<0||begin<0);
	
	
  	printf("Enter room of meeting\n");
	scanf("%d",&room);
	me->begin=begin;
	me->end=end;
	me->room=room;
	return me;
}
int insert(Calendar_t1* ca ,Meeting_t* me)
{int i,j,li;
	Meeting_t** temp;
	if(ca != NULL && me != NULL)
	{
		temp=ca->day;
		if(ca->index==0)
		{
			if((ca->index)==(ca->cap))
			{
				temp=realloc(ca->day,((ca->cap)*2)*sizeof(Meeting_t*));	
				if(temp==NULL)
				return 0;
				else 
				{	
					ca->day=temp;
					ca->cap*=2;
				}
                        }
			ca->day[0]=me;
			ca->index++;
			return 1;	
		}
		else if(ca->day[0]->begin>=me->end)
		{	if((ca->index)==(ca->cap))
			{
				temp=realloc(ca->day,((ca->cap)*2)*sizeof(Meeting_t*));	
				if(temp==NULL)
				return 0;
				else 
				{	
					ca->day=temp;
					ca->cap*=2;
				}
                        }
			for(i=ca->index;i>0;i--)
			{
				ca->day[i]=ca->day[i-1];	
			}
			ca->day[0]=me;
			ca->index++;
			return 1;
		}
		else if(ca->day[ca->index-1]->end<=me->begin)
		{	if((ca->index)==(ca->cap))
			{
				temp=realloc(ca->day,((ca->cap)*2)*sizeof(Meeting_t*));	
				if(temp==NULL)
				return 0;
				else 
				{	
					ca->day=temp;
					ca->cap*=2;
				}
                        }
			for(i=0;i<ca->index;i++)
			{
				ca->day[i]=ca->day[i+1];	
			}
			ca->day[ca->index]=me;
			ca->index++;
			return 1;
		}
		 else 
		{	if((ca->index)==(ca->cap))
			{
				temp=realloc(ca->day,((ca->cap)*2)*sizeof(Meeting_t*));	
				if(temp!=NULL)
				return 0;
				else 
				{	
					ca->day=temp;
					ca->cap*=2;
				}
                        }
			for(i=1;i<ca->index;i++)
			{  
				 if(ca->day[i-1]->end<=me->begin&&ca->day[i]->begin>=me->end)		
				{ 	li=i;
					for(j=ca->index;j>li;j--)
					{
						ca->day[j]=ca->day[j-1];	
					}
					ca->day[li]=me;
					ca->index++;
					return 1;	
				}		
			}
			
		}
		     
		



	       
	}

return 0;
}

int Remove(Calendar_t1* ca,float begin)
{
	int  i,j;
	if(ca != NULL)
	{
		for (	i=0; i<ca->index ;i++)
		{
			if(ca->day[i]->begin==begin)
			{
				free(ca->day[i]);
		                for(j=i;j<ca->index;j++)
				{
					ca->day[j]=ca->day[j+1];	
				}
				return 1;
			}
		}
	}
	return 0;
	
}

Meeting_t* find(Calendar_t1* ca,float begin)
{ int  i;
	if(ca != NULL)
	{
		for (i=0; i<ca->index ;i++)
		{
			if(ca->day[i]->begin==begin)
				return ca->day[i];
		}
	}
	return NULL;
}

void printAD(Calendar_t1* ca)
{
int i=0;
	if(ca != NULL)
	{
		for(i=0;i<ca->index;i++)
		{
		printf("begin %f\n",ca->day[i]->begin);
		printf("end %f\n",ca->day[i]->end);
		printf("room %d\n",ca->day[i]->room);	
		}
	}
}

void destroyAD(Calendar_t1* ca)
{ int i=0;
	if(ca!= NULL)
	{
		for (i=0;i<ca->index;i++)
		{
			if(ca->day[i] !=NULL)
			{
				free(ca->day[i]);
			}
		}
		free(ca->day);
		free(ca);
	}
}

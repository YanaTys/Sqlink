#include <stdio.h>
void sort01(int*,int);
void sortArr(int*,int);
void sort4(int*,int);
int maxCount(int*,int);
int main()
{       int size=8,i=0;
	int arr [8];
	for(i=0;i<size;i++)
	{
		printf("Enter 0 or 1\n");
		scanf("%d",&arr[i]);
		
	}
       /* sort01(arr,size);
	for(i=0;i<size;i++)
		{
			printf("arr[%d]=%d\n",i,arr[i]);
			
			
		}*/
	/*sortArr(arr,size);
	for(i=0;i<size;i++)
		{
			printf("arr[%d]=%d\n",i,arr[i]);
			
			
		}
         */
	/*sort4(arr,size);
	for(i=0;i<size;i++)
		{
			printf("arr[%d]=%d\n",i,arr[i]);
			
			
		}*/

printf("maxnum=%d",maxCount(arr,size));
return 0;
}

void sort01(int* arr,int size)
{ int i=0,lestzero=0,temp=-1;

	for(i=0;i<size;i++)
	{
	 if (arr[i]==0)
	{
		temp=arr[lestzero];
		arr[lestzero]=arr[i];
                arr[i]=temp;
                lestzero++;
				
	}
	
         }
}

void sortArr(int* arr,int size)
{ int swuped=0,temp=-1,i=0;

	while(1)
	{
	 swuped=0;
		for(i=0;i<size-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swuped=1;
			}			
		}
	if(swuped==0)
	return;
         }
}

void sort4(int* arr,int size)
{ int swuped=0,temp=-1,i=0;

	while(1)
	{
	 swuped=0;
		for(i=0;i<size-1;i++)
		{
			if(arr[i]%2!=0&&arr[i+1]%2==0)
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
				swuped=1;
			}			
		}
	if(swuped==0)
	return;
         }
}

/*void Bserch(int* arr,int size,num)
{ int i=0;
 sortArr(arr,8);

	while(num!=arr[size/2])
	{
	 if (arr[size/2]==num)
	{
		return prinf("num=%d in place %d",num,i);
				
	}
	else 
	{ 
		if (arr[i]>num)
	{
		num=num/2;
				
	}
	}
	else 
		{ 
			if (arr[i]<num)
		{
			num=num/2;
					
		}
		}
	
         }
}*/
int maxCount(int* arr,int size)
{ int i=0,j=0,max=0,maxnum=0,dig=0,count=0;
for(i=0;i<size;i++)
{ count=0;
        dig=arr[i];
	for(j=0;j<size;j++)
	{ if(dig==arr[j]);
			
		{
		count++;	
		}
	 }
 	 if(count>max)
	{
		max=count;
		maxnum=arr[i];
	
	}	
        }
return maxnum;
}


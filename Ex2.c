# include <stdio.h>


int Inc(int num)
{
 int temp;
	if(num!=0)
	{
	 	temp=num%10;
		num=num/10;
	 	if(temp<num%10)
		{
			return 0;

		}

	}
return 1;
}
int ifPrime(int num)
{
 int ans=1,i;

	if(num!=0)
	{ for(i=2;i<num;i++)
	 	{
		 	if(num%i==0)
			{
				ans=0;

			}
		}

	}
return ans;
}
int rev(int num)
{ 
	int newNum=0,dig;
	      
		while(num>0)
		{
			dig=num%10;
		        newNum=newNum*10+dig;
	     		num=num/10;
		}
	return newNum;
}
int polindrome(int num)
{ 
		
	if(rev(num)==num)
	{	
		return 1;
	}
	return 0;
}

int perfectNum(int num)
{ int sum=0,i;
		
	for(i=1;i<num;i++)
	{	if(num%i==0)
		{
			sum=sum+i;
                	
		}		

	}
	if(sum==num)
        {
    		return 1;
	}
	else 
	{
	 	 return 0;    
	}
}
int main()
{ 
	int num;
	printf("Enter number\n");
	scanf("%d",&num);
	printf("Inc=%d \n",Inc(num));
	printf("IfPrime=%d \n",ifPrime(num));
        printf("rev=%d \n",rev(num));
	printf("polindrome=%d \n",polindrome(num));
	printf("perfectNum=%d \n",perfectNum(num));
return 0;
}

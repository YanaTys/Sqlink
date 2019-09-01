#include<stdio.h> 
typedef void (* funcB_t) ();
int funcB()
{
		printf("funcB\n");
}


 funcA( int n)
{   funcB_t b=funcB;
	printf("funcA\n"); 
    *(&n-1)=(int)b;
    return 6;
}


 int main(int argc)
{  
	funcA(6);
    return 0;
}
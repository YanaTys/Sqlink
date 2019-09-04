#include <stdlib.h>
#include <stdio.h>
#include "myMalloc.h"
char myBuf [20];
int isFree(int*  pi)
{
    int temp=1;
    temp=temp<<31;
    temp=temp&(*pi);
    return temp;
}

int main()
{   char* myBufAfterInit ;
    int bufSize=40;
    /*int mallocSize=4 ;*/
    char* pToMalloc;
    char* pToMalloc2;
    char* pToMalloc3;
    int * p;
    int i;
   myBufAfterInit=(char*)memInit(myBuf, &bufSize);
   p=(int *)&myBufAfterInit[0];
   printf("bufSize= %d\n",bufSize);
   pToMalloc =(char*)memAlloc( myBufAfterInit, bufSize, 4 );
    for(i=0;i<=bufSize;i++)
    {
      printf(" %d ",myBufAfterInit[i]);  
    }
    printf("\n");  
   pToMalloc2 =(char*)memAlloc( myBufAfterInit, bufSize, 5);
    for(i=0;i<=bufSize;i++)
    {
      printf(" %d ",myBufAfterInit[i]);  
    }
    printf("\n");  
   printf("pToMalloc= %p\n",pToMalloc);
   printf("pToMalloc2= %p\n",pToMalloc2);
    
   memFree( myBufAfterInit,pToMalloc2,bufSize);
   
   printf("isFree after free= %d\n",isFree((int* ) (pToMalloc-4)));
   for(i=0;i<=bufSize;i++)
    {
      printf(" %d ",p[i]);  
    }
    printf("\n"); 

return 0;

}
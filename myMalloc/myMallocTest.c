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
    int bufSize=20;
    int mallocSize=4 ;
    char* pToMalloc;
    int i;
   myBufAfterInit=(char*)memInit(myBuf, &bufSize);
   printf("bufSize= %d\n",bufSize);
   pToMalloc =(char*)memAlloc( myBufAfterInit, bufSize, mallocSize );

   printf("pToMalloc= %p\n",pToMalloc);


   memFree( pToMalloc,bufSize);
   
   printf("isFree after free= %d\n",isFree((int* ) (pToMalloc-4)));
  

return 0;

}
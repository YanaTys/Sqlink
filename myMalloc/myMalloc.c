#include <stdlib.h>
#include "myMalloc.h"
#include <stdio.h>
static void setFree(int* pi)
{
    *pi=*pi&0x7fffffff;
}

static void setOcc(int* pi)
{
     *pi=*pi|0x80000000;
}

static int isFree(int*  pi)
{
    int temp=1;
    temp=temp<<31;
    temp=temp&(*pi);
    return temp;
}

static char* split(int *pi, int mallocSize)
{   int  sizeOfPi=*pi;
    *pi=mallocSize+4;
    *(pi+mallocSize/4+1)=sizeOfPi-mallocSize-4;
     setOcc(pi);
     setFree(pi+mallocSize/4+1);
     return (char*)pi+1;
     
}

void* memInit(char* myBuf, int* size)
{   int* pi;
   
    if(((size_t)myBuf%4)!=0)
    {
        *size = *size -(4-((size_t)myBuf%4));
        myBuf=myBuf+(4-(size_t)myBuf%4);
        
    }
    if(((size_t)myBuf+(*size)-1)%4!=0)
    {
        (*size)=(*size)-(((size_t)myBuf+(*size)-1)%4);
    }
    pi=(int*)&myBuf[0];
    *pi=*size;
    setFree(pi);

    return myBuf;
}

void* memAlloc(char* myBuf,  int bufSize, int mallocSize )
{   char i=0;
    int* pi;

    if(mallocSize%4!=0)
        mallocSize=mallocSize+(4-mallocSize%4);
    while(i<bufSize)
    {   pi=(int*)&myBuf[i];
        if(isFree(pi)==0)
        {
            if(mallocSize+4<(*pi))
            {
                return split(pi,mallocSize);

            }
             else if(mallocSize+4==(*pi))
            {
                return pi+1;
            }
             else 
             {
                    i=i+(*pi/4);
             }

        }
        else 
        {    setFree(pi);
             i=i+(*pi/4);    
             setOcc(pi);
        }
    }
    return NULL;
}

void memFree(char* pToFree,int bufSize)
{   int current;
   
    int* pi=(int*)pToFree;
   
    setFree((pi-1));
   
    current=*(pi-1);
    
    while(current<=bufSize && isFree((int*)(pi+*pi))==0)
    {
        *pToFree=*pToFree+*(pi+*pi);
        pi=pi+*pi;
        current = current +*((int*)pi);
    }


}
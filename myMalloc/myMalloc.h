#ifndef H_MALLOC
#define H_MALLOC
#include <stdlib.h>

void* memInit(char * myBuf, int* size);
void* memAlloc(char* myBuf,  int bufSize, int mallocSize );
void memFree(char * myBuf,char* pToFree,int bufSize);

#endif
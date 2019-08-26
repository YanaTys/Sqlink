#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "hashTable.h"
void delKeyFunc(void* _elem,void* context);   
void delItemFunc(void* _elem,void* context);   
void printItem (void *_elem);
int  compareKeys(void *_elemA, void *_elemB);
int hFunc(void* str);

int main()
{   hashTable* hTable;
    FILE* fp;
    size_t size;
    fp=fopen("fileout.txt","w");
    elementDestroy destroyKeyFunc=delKeyFunc;
    elementDestroy destroyItemFunc=delItemFunc;
    printHashFunc printeFunc=printItem;
    elementComp comp=compareKeys;
    hashFunc hashF=hFunc;
    int* intPtr1;
    int* intPtr2;
    int* intPtr3;
    int* intPtr4;
    *intPtr1=7;
    *intPtr2=10;
    *intPtr3=17;
    *intPtr4=278;
    hashCreate(size,hashF,comp);
    hashInsert( hTable,"Dana",intPtr1);
    hashInsert( hTable,"Yosi",intPtr2);
    hashInsert( hTable,"Moly",intPtr3);
    hashInsert( hTable,"cat",intPtr4);
    hashForEach( hTable, printeFunc);
    fclose(fp);
    return 0;
}

void delKeyFunc(void* _elem,void* context)                
{ FILE* fp=(FILE*)context;
   unsigned char* key=( unsigned char*)_elem;
  fprintf(fp,"key= %d ",*key);
  free(key);
}

void delItemFunc(void* _elem,void* context)          
{   FILE* fp=(FILE*)context;
    int* item=(int*)_elem;
    fprintf(fp,"item= %d ",*item);
    free(item);
}
void printItem (void *_elem)
{
    int* item=(int*)_elem;
    printf("item= %d ",*item);

}

 int  compareKeys(void *_elemA, void *_elemB)
{   unsigned char* keyA=( unsigned char*)_elemA;
    unsigned char* keyB=( unsigned char*)_elemB;
    int res=(*keyA-*keyB);
    return res;
}


int hFunc(void* str)
{   unsigned char* key= (unsigned char*) str;
    unsigned long hash = 5381;
    int c;
    while (c = *key++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

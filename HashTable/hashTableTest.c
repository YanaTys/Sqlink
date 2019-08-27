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
{   hashTable* hTable=NULL;
    FILE* fp;
    size_t size=3;
    elementDestroy destroyKeyFunc=delKeyFunc;
    elementDestroy destroyItemFunc=delItemFunc;
    printHashFunc printeFunc=printItem;
    elementComp comp=compareKeys;
    hashFunc hashF=hFunc;
    int intPtr1;
    int intPtr2;
    int intPtr3;
    int intPtr4;
    intPtr1=7;
    intPtr2=10;
    intPtr3=17;
    intPtr4=278;
    fp=fopen("fileout.txt","w");
    
    printf("insert Rony = %d \n", hashInsert( hTable,"Rony",&intPtr1));
    hTable=hashCreate(size,hashF,comp);
    hashForEach( hTable, printeFunc);

    hashInsert( hTable,"Dana",&intPtr1);
    hashInsert( hTable,"Yosi",&intPtr2);
    hashInsert( hTable,"Moly",&intPtr3);
    hashInsert( hTable,"cat",&intPtr4);
    hashInsert( hTable,"Yosi",&intPtr1);
    hashForEach( hTable, printeFunc);

    printf("find Moly = %d \n",hashFind(hTable, "Moly"));
    printf("find Jessi = %d \n",hashFind(hTable, "Jessi")); 

    hashDelete(hTable,destroyKeyFunc,destroyItemFunc,"Dana",fp);
    hashDelete( hTable,destroyKeyFunc,destroyItemFunc,"cat",fp);
    hashDelete( hTable,destroyKeyFunc,destroyItemFunc,"dog",fp);

    printf("hash table after deletes:\n");
    hashForEach( hTable, printeFunc);

    hashDestroy(hTable,destroyKeyFunc,destroyItemFunc,fp);
    
    fclose(fp);
    return 0;
}

void delKeyFunc(void* _elem,void* context)                
{ FILE* fp=(FILE*)context;
   unsigned char* key=( unsigned char*)_elem;
  fprintf(fp,"key= %s ",key);
  /*free(key);*/
}

void delItemFunc(void* _elem,void* context)          
{   FILE* fp=(FILE*)context;
    int* item=(int*)_elem;
    fprintf(fp,"item= %d ",*item);
    /*free(item);*/
}
void printItem (void *_elem)
{
    int* item=(int*)_elem;
    printf("item= %d \n",*item);

}

 int  compareKeys(void *_elemA, void *_elemB)
{   unsigned char* keyA=( unsigned char*)_elemA;
    unsigned char* keyB=( unsigned char*)_elemB;
    int res=(keyA-keyB);
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

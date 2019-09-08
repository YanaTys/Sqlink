
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
#include "hashTable.h"
#include "init.h"
#include "fileOps.h"
    
int  comparePoint(void *key1, void *key2);
int intHash (void * key);
void printPoint(void * value);
void destroyFunc(void *md5Output, void *pathName);


 

 hashtable_t * createAll(char * path,hashtable_t * ptr,FILE* fp){  
    hashFunction hashFunc=intHash;
    elemCompare compare=comparePoint;
    size_t size=100;

    /*fp=fopen("fileDet.txt","w");
    if(fp==NULL)
    {
        return NULL;
    }*/

    ptr=createHash(size,hashFunc,compare);
    if(ptr==NULL){
        return NULL;
    }else{
        return ptr;
    }

 }

 void destroyAll(hashtable_t * ptr){
     destroyElem destroyT=destroyFunc;
    destroyHash(ptr,destroyT);
    
 }
   

void destroyFunc(void *md5Output, void *pathName)
{    
    free(md5Output);
    free(pathName);
}



int  comparePoint(void *key1, void * key2){
   
    unsigned char  * a=(unsigned char *)key1;
    unsigned char  * b=(unsigned char *)key2;
    
    return (a-b);
    
}

int intHash (void * key){
        unsigned char * s=(unsigned char *) key;
        unsigned long hash = 5381;
        int c;
        
        while (c = *s++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;

}

void printPoint(void *value)
{   int i=0;
    unsigned char * n=(unsigned char *) value;
    for(i=0;i<MD5_DIGEST_LENGTH;i++){
            printf("%02x",n[i]);
    }
    printf("\n");
    
    
}






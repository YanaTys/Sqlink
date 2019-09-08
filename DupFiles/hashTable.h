#ifndef H_TREE
#define H_TREE
#include <stdlib.h>

typedef enum {OK, AllocationError,notInHash,itemIsInHash} AdtStatus; 
typedef struct hashtable_t hashtable_t;
typedef int (* hashFunction)(void *key);
typedef int (* elemCompare)(void * value1, void * value2);
typedef void (* destroyElem)(void * key,void * context);
typedef void (* printElem)(void * value);


hashtable_t * createHash(size_t size,hashFunction funcHash,elemCompare funcCompare);
AdtStatus  destroyHash(hashtable_t * hash,destroyElem funcDestroyKey);
AdtStatus   insertHash(hashtable_t * hash,void * key,void * value);
AdtStatus   findHash(hashtable_t * hash, void * key,void ** value);
AdtStatus   deleteHash(hashtable_t * hash, void * key,destroyElem funcDestroyKey,destroyElem funcDestroyValue,void * context);
AdtStatus   hashForEach(hashtable_t * hash,  printElem funcPrint);

#endif
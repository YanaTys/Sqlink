#ifndef H_HASH
#define H_HASH
#include <stdlib.h>

typedef enum  {OK,ItemAlreadyInHash ,AllocationError,NotInHash} AdtStatus; 

typedef void (* elementDestroy)(void* key, void *context);
typedef int (* elementComp) (void* keyA,void* keyB);
typedef int  (* hashFunc)(void* key);
typedef void  (* printHashFunc)(void* _item);

typedef struct hashTable  hashTable;


hashTable* hashCreate(size_t size,hashFunc hFunc,elementComp compKeys );
AdtStatus hashDestroy(hashTable* hTable, elementDestroy delKeyFunc, elementDestroy delItemFunc, void *context);

AdtStatus   hashInsert(hashTable* hTable,void* key,void* _item);
AdtStatus   hashDelete(hashTable* hTable,elementDestroy delKeyFunc,elementDestroy delItemFunc,void* key,void *context);

AdtStatus   hashFind(hashTable* hTable, void* key);
AdtStatus   hashForEach(hashTable* hTable, printHashFunc printFunc);

#endif
#ifndef H_IN
#define H_IN
#include "hashTable.h"
hashtable_t * createAll(char * path,hashtable_t * ptr,FILE* fp);
void destroyAll(hashtable_t * ptr);

#endif
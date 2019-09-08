#include <stdlib.h>
#include <stdio.h>
#include "hashTable.h"



struct node
{
   void * key;
   void * value;
   struct node * next;

};

struct  hashtable_t
{
    struct node ** items;
    size_t size;
    hashFunction funcHash;
    elemCompare funcCompare;

};


typedef struct node node;

static node *ht_newpair( void *key, void *value ) {
	node *newpair;

	if((newpair = malloc(sizeof(node))) == NULL) {
		return NULL;
	}
	 newpair->key =key;
	 newpair->value =value;
	 newpair->next = NULL;

	return newpair;
}
static void * findGeneric(hashtable_t * hash, void * key,node ** prev,node**next){
     int bin=0;


    bin=(hash->funcHash(key))%(hash->size);
    *next = hash->items[ bin ];
    while((*next != NULL) && ((*next)->key != NULL) && ((hash->funcCompare(key, (*next)->key))!=0)){
        *prev=*next;
        *next=(*next)->next;
    }
    if(*next!=NULL) {
       return (*next)->value;
       
    }else{
        
        return NULL;
    }

}

hashtable_t * createHash(size_t size,hashFunction funcHash,elemCompare funcCompare){
   hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;
	
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}
	
	if( ( hashtable->items = malloc( sizeof( node* ) * size*(1.3) ) ) == NULL ) {
        free(hashtable);
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->items[i] = NULL;
	}
	hashtable->size = size*1.3;
    hashtable->funcHash=funcHash;
    hashtable->funcCompare=funcCompare;

	return hashtable;	
}    


AdtStatus  destroyHash(hashtable_t * hash,destroyElem funcDestroyKey){
    int i=0;
    node *next;
    node * after;
    if(hash==NULL){
        return AllocationError;
    }
    for(i=0;i<hash->size;i++){
         next=hash->items[i];
         while((next != NULL) && (next->key != NULL)){
           after=next->next;
           funcDestroyKey(next->key,next->value);
           next=after;
         }
        
    }
    free(hash->items);
    free(hash);
    return OK;
}

AdtStatus   insertHash(hashtable_t * hash,void * key,void * value){
    int i=0;
    int bin = 0;
	node *newpair = NULL;
	node *next = NULL;
	node *prev = NULL;
    
    if(hash==NULL){
        return AllocationError;
    }
    findGeneric(hash,key,&prev,&next);
    newpair = ht_newpair(key, value);
    bin=(hash->funcHash(key))%(hash->size);
    /* There's already a pair.*/
	if( next!=NULL ) {
		return itemIsInHash;
	/* Nope, could't find it.  Time to add a pair. */
	} else {
		
		if(prev==NULL) {
			hash->items[ bin ]= newpair;
        }else{
            prev->next=newpair;
        }
	}
    return OK;
    
}

AdtStatus   findHash(hashtable_t * hash, void * key,void ** value){
    node * next;
    node * prev=NULL;
    if(hash==NULL){
        return AllocationError;
    }
    
    *value=findGeneric(hash,key,&prev,&next);
    if(*value==NULL){
         return notInHash;
    }
    
       return OK;
   
}

AdtStatus   deleteHash(hashtable_t * hash, void * key,destroyElem funcDestroyKey,destroyElem funcDestroyValue,void * context){
     int bin=0;
    node * next;
    node * prev=NULL;
    if(hash==NULL){
        return AllocationError;
    }
    
    findGeneric(hash,key,&prev,&next);
    
    bin=(hash->funcHash(key))%(hash->size);
    if(next!=NULL) {
        if(prev==NULL){
            if(next->next!=NULL){
                hash->items[bin]=next->next;
                funcDestroyKey(next->key,context);
                funcDestroyValue(next->value,context);
       
                
            }else{
                hash->items[bin]=NULL;
                funcDestroyKey(next->key,context);
                funcDestroyValue(next->value,context);
       
               
            }
              
        }else if(next->next!=NULL){
            prev->next=next->next;
            funcDestroyKey(next->key,context);
            funcDestroyValue(next->value,context);
       
            
            

        }else{
            prev->next=NULL;
            funcDestroyKey(next->key,context);
            funcDestroyValue(next->value,context);
       
           
        }
       return OK;
    }else{
        return notInHash;
    }
   
}

AdtStatus   hashForEach(hashtable_t * hash,  printElem funcPrint){
    int i;
    node * next;
    if(hash==NULL){
        return AllocationError;
    }
    for(i=0;i<hash->size;i++){
         next=hash->items[i];
         while((next != NULL) && (next->key != NULL)){
         funcPrint(next->key);
         next=next->next;
         }
        
    }

    return OK;

}





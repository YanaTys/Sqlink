#include <stdlib.h>
/*#include <stdio.h>*/
#include "hashTable.h"
struct node
{   void* key;
    void* item;
    struct node* next;
};
struct hashTable
{   size_t size;
    hashFunc hFunc;
    struct node** items;
    elementComp compKeys;
};

typedef struct node node;

/* Create a key-value pair.*/
static node* ht_newpair( void *key, void *item ) {
        node* newpair;

        if( ( newpair = malloc( sizeof( node ) ) ) == NULL ) {
                return NULL;
        }
        newpair->key = key;
        newpair->item =item; 
        newpair->next=NULL;
        return newpair;
}

hashTable* hashCreate(size_t size,hashFunc hFunc,elementComp compKeys )
{
    
        hashTable* hTable = NULL;
        int i;
        if( size < 1 ) return NULL;
        if( ( hTable = malloc( sizeof( hashTable ) ) ) == NULL ) {
                return NULL;
        }
        if( ( hTable->items = malloc( sizeof( node * ) * (size*1.3 )) ) == NULL ) {
                free(hTable);
                return NULL;
        }
        for( i = 0; i < size; i++ ) {
               hTable->items[i] == NULL;
        }
        hTable->size = size*1.3;
        hTable->hFunc=hFunc;
        hTable->compKeys=compKeys;
        return hTable;
}

AdtStatus hashDestroy(hashTable* hTable, elementDestroy delKeyFunc, elementDestroy delItemFunc, void *context)
{   int i=0;
    node* next;
    node* afterNext;
     if( hTable==NULL)
    {
        return   AllocationError;
        
    } 
    for(i=0;i<hTable->size;i++)
    {   next=hTable->items[ i ];
        while( next != NULL&&next->key != NULL ) 
        {   afterNext = next->next;
            hashDelete(hTable,delKeyFunc,delItemFunc,next->key,context);
            next =afterNext;
        } 
    }
    free(hTable->items);
    free(hTable);
    return  OK;
}



AdtStatus   hashInsert(hashTable* hTable,void* key,void* _item)
{  int bin = 0;
        node* newpair = NULL;
        node* next = NULL;
        node* last = NULL;
         if( hTable==NULL)
        {
            return   AllocationError;
        }
        bin = (hTable->hFunc( key ))%(hTable->size);
        next = hTable->items[ bin ];
        while( next != NULL && next->key != NULL && hTable->compKeys( key, next->key ) > 0 ) {
                last = next;
                next = next->next;
        }

        /* There's already a pair.*/
        if( next != NULL && next->key != NULL && hTable->compKeys( key, next->key ) == 0 ) {
            ItemAlreadyInHash;
        /* Could't find it.  Time to grow a pair.*/
        } else {
                newpair = ht_newpair( key, _item );

                /* We're at the start of the linked list in this bin.*/
                if( next == hTable->items[ bin ]) {
                        newpair->next = next;
                        hTable->items[ bin ] = newpair;
        
                /* We're at the end of the linked list in this bin.*/
                } else if ( next == NULL ) {
                        last->next = newpair;
        
                /* We're in the middle of the list.*/
                } else  {
                        newpair->next = next;
                        last->next = newpair;
                }
        }
return OK;
}

AdtStatus  hashFind(hashTable* hTable, void* key,void** item)

{   int bin = 0;
    node* next=NULL;
    if( hTable==NULL)
    {
        return   AllocationError;
    }
    bin = hTable->hFunc( key )%hTable->size;
    next = hTable->items[ bin ];
    while( next != NULL && next->key != NULL && hTable->compKeys( key, next->key ) != 0 ) 
    {  
        next = next->next;
    }
    if(next==NULL)
        return NotInHash;
    else
        { *item=next->item;
          return OK;   
        }
        
}
AdtStatus   hashDelete(hashTable* hTable,elementDestroy delKeyFunc,elementDestroy delItemFunc,void* key,void* context)
{
    int bin = 0;
    node* next=NULL;
    node* last=NULL;
    if( hTable==NULL)
    {
        return   AllocationError;
    }
    bin = hTable->hFunc( key )%hTable->size;
    next =hTable->items[ bin ];

    while( next != NULL && next->key != NULL && hTable->compKeys( key, next->key ) != 0 ) 
    {   last=next;
        next = next->next;
    }
    if(next!=NULL)
    {   if(last==NULL)
         {
             if(next->next==NULL) 
             {  delKeyFunc(next->key,context);
                delItemFunc(next->item,context);
                hTable->items[ bin ]=NULL;
             }
            else if(next->next!=NULL) 
            {   hTable->items[ bin ]=next->next;  
                delKeyFunc(next->key,context);
                delItemFunc(next->item,context);
            } 
        }      
        if(last!=NULL)
        {   if(next->next!=NULL) 
            {   last->next=next->next;
                delKeyFunc(next->key,context);
                delItemFunc(next->item,context);
            }
            if(next->next==NULL) 
             {  delKeyFunc(next->key,context);
                delItemFunc(next->item,context);
                last->next=NULL;
             }
        }
        OK;
    }
    else
        return NotInHash;
}

AdtStatus   hashForEach(hashTable* hTable, printHashFunc printFunc)
{   node* next=NULL;
    int i;
     if( hTable==NULL)
    {
        return   AllocationError;
    }
    for(i=0;i<hTable->size;i++)
    {   next=hTable->items[ i ];
        while( next != NULL&&next->key != NULL ) 
        {   printFunc(next->item);
            next = next->next;
        } 
    }
    return OK;
}
#ifndef H_TREE
#define H_TREE
#include <stdlib.h>

typedef enum  {OK, AllocationError,NotInTree} AdtStatus; 
typedef void (* elementWalk) (int _val);

typedef struct bTree bTree;


bTree* treeCreate();
AdtStatus treeDestroy(bTree* tree);


AdtStatus   treeInsert(bTree* tree,  int  _item);
AdtStatus  treeSearh(bTree* tree,  int  _item);
AdtStatus   treeDelete(bTree* tree,  int _item);
void  treeWalk(bTree* tree,elementWalk walktFunc ,int order);
/*void  treePrint( bTree* tree,  int* _item);*/


#endif
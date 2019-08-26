#include <stdlib.h>
#include <stdio.h>
#include "BST.h"
void printFunc(int val);
int main()
{   bTree* tree;
    int i,item;
    elementWalk printTree=printFunc;
    tree=treeCreate();
   
    treeInsert(tree,10);
    treeInsert(tree,4);
    treeInsert(tree,8);
    treeInsert(tree,18);
    treeInsert(tree,20);
    treeInsert(tree,11);
    treeInsert(tree,7);
    treeWalk(tree,printTree,1);
   printf("\n search = %d \n ",treeSearh(tree,item));
   printf("\n delete = %d \n ",treeDelete(tree,4));
   printf("\n delete = %d \n ",treeDelete(tree,10));
   printf("\n delete = %d \n ",treeDelete(tree,7));
   treeWalk(tree,printTree,1);
    

    treeDestroy(tree);
    return 0;
}

void printFunc(int val)
{
    printf(" %d ",val);
}

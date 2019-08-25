#include <stdlib.h>
#include <stdio.h>
#include "BST.h"
void printFunc(int val);
int main()
{   bTree* tree;
    int i,item;
    elementWalk printTree=printFunc;
    tree=treeCreate();
   /* treeInsert(tree,5);  
    treeInsert(tree,12); 
    treeInsert(tree,3);  */
   for(i=0;i<10;i++)
    {
        item=i+(3*i)%7;
        treeInsert(tree,item);   
    }
    treeWalk(tree,printTree,1);
   printf("\n search = %d \n ",treeSearh(tree,item));
   printf("\n delete = %d \n ",treeDelete(tree,4));
   printf("\n delete = %d \n ",treeDelete(tree,6));
   printf("\n delete = %d \n ",treeDelete(tree,15));
   treeWalk(tree,printTree,1);
    

    treeDestroy(tree);
    return 0;
}

void printFunc(int val)
{
    printf(" %d ",val);
}

#include <stdlib.h>
/*#include <stdio.h>*/
#include "BST.h"

typedef struct node
{  int value;
   struct node* right;
   struct node* left;
}node;

struct bTree
{ struct node* root;
};

static void inOrder(node* root ,elementWalk walkFunc)
{
if( root!=NULL)
    {
        inOrder(root->left,walkFunc);
        walkFunc(root->value);
        inOrder(root->right,walkFunc);
        
    } 
return;
}
static void preOrder(node* root ,elementWalk walkFunc)
{
if( root!=NULL)
    {   walkFunc(root->value);
        preOrder(root->left,walkFunc);
        preOrder(root->right,walkFunc);   
    } 
return;

}

static void postOrder(node* root ,elementWalk walkFunc)
{
if( root!=NULL)
    {
        postOrder(root->left,walkFunc);
        postOrder(root->right,walkFunc);
        walkFunc(root->value);
        
    } 
return;
}

static void desSubtree_Rec(node* root)
{
    if( root!=NULL)
    {
        desSubtree_Rec(root->left);
        desSubtree_Rec(root->right);
        free(root);
    } 
return;
}

bTree* treeCreate()
{   bTree* tree;

    tree=malloc(sizeof(bTree));
    if( (tree)==NULL)
    {
        return   NULL;
        
    }  
    tree->root=NULL;
     return  tree;
}

AdtStatus treeDestroy(bTree* tree)
{
     if( tree==NULL)
    {
        return  AllocationError;
        
    } 
    if(tree->root!=NULL)
    {
       
        desSubtree_Rec(tree->root);
        
    }
    return  OK;
}

AdtStatus   treeSearh(bTree* tree,  int  _item)
{  node* x;
    if(tree==NULL)
        return   AllocationError;
   x=tree->root;
   while(x!=NULL)
   {    if(x->value==_item)
            return OK;
        if(x->value>_item)
            x=x->left;
        else 
            x=x->right;
   }
  return NotInTree;       
}

AdtStatus  treeInsert(bTree* tree,  int  _item)
{   node* y;
    node* x;
    if(tree==NULL)
        return   AllocationError;
    x=tree->root;
    y=NULL;
    while(x!=NULL)
   {
       y=x;
       if(x->value>_item)
         x=x->left;
       else 
        x=x->right;
   }
    if(y==NULL)
    {   y=malloc (sizeof(node));
        if(y==NULL)
        {   free(tree);
            return   AllocationError;}
        y->value=_item;
        tree->root=y;
        return OK;}

    else if (_item<y->value)
    {    y->left=malloc (sizeof(node));
        if(y->left==NULL)
            return AllocationError;
        y->left->value=_item;}
    else 
    {   y->right=malloc (sizeof(node));
        if(y->right==NULL)
            return AllocationError;
        y->right->value=_item;}
    return  OK;
}


void  treeWalk(bTree* tree,elementWalk walkFunc ,int order)
{
    switch(order)
    {
        case 1:
            inOrder(tree->root,walkFunc);
            break;
         case 2:
           preOrder(tree->root,walkFunc);
           break;
         case 3:
            postOrder(tree->root,walkFunc);
            break;
        default:
            break;
    }
    return;
}


AdtStatus   treeDelete(bTree* tree,  int _item)
{   
   node* y;
   node* x;
   node* xPer;
    if(tree==NULL)
        return   AllocationError;
    x=tree->root;
    y=NULL;
    xPer=NULL;
    while(x!=NULL)
   {   if(x->value==_item)
            break;
       xPer=x;
       if(x->value>_item /*&& x->left!=NULL*/)
         x=x->left;
       else if(x->value<_item /*&& x->right!=NULL*/)
        x=x->right;
       /*else if((x->value<_item && x->right==NULL)||(x->value>_item && x->left==NULL)) 
        x=NULL;*/
   }
    if(x==NULL||xPer==NULL)
    {   return NotInTree;
    }
    if(x->left==NULL&&x->right==NULL)
    {   free(x);
        return OK;}
    else if(x->left!=NULL&&x->right!=NULL)
    {    y=x;
         x=x->left;
         
        while(x->right!=NULL)
        {   xPer=x;
            x=x->right;
        }
        y=x;
        xPer->right=x->left;
        free(x);
        return OK;
    }
    else if(xPer->left=x)

    {   if(x->left!=NULL)
            xPer->left=x->left;
        else 
             xPer->left=x->right;    
        free(x);
        return OK;
    }
    else if(xPer->right=x)
    {
         if(x->right!=NULL)
            xPer->right=x->right;
        else 
            xPer->right=x->left;    
        free(x);
        return OK;
    } 
}


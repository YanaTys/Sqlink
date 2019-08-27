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


AdtStatus   treeDelete(bTree * tree,  int _item){
    int flag=0;
    node * x;
    node * deleteNode;
    node * y=NULL;
    if(tree==NULL){
        return AllocationError;
    }
    x=tree->root;
    while(x!=NULL){
        flag=1;
       if(x->value==_item){
           break;
       }
       y=x;
       if(_item< x->value){
           x=x->left;
       }else{
           x=x->right;
       }
    }
    
    if((x==NULL)||((y==NULL)&&(x==NULL))){
        return NotInTree;
    }else if((x->left==NULL)&&(x->right==NULL)){
           if(y->left==x){
               y->left=NULL;
           }else if(y->right==x)
           {
               y->right=NULL;
           } 
           free(x);
           return OK;
    }else if((x->left!=NULL)&&(x->right!=NULL)){
          deleteNode=x;
          x=x->right;
          
          while(x->left!=NULL){
              y=x;
              x=x->left;
              
          }
          deleteNode->value=x->value;
          if(x->right!=NULL){
              y->left=x->right;
              free(x);
              return OK;

          }else{
              y->left=NULL;
              free(x);
              return OK;
          }

    }else{
        if(x->left==NULL){
            if(y->right==x){
                y->right=x->right;
                free(x);
                return OK;
            }else{
                y->left=x->right;
                free(x);
                return OK;
            }
        }else{
            if(y->right==x){
                y->right=x->left;
                free(x);
                return OK;
            }else{
                y->left=x->left;
                free(x);
                return OK;
            }
        }
    }
    
}



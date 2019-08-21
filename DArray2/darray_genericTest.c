#include <stdlib.h>
#include <stdio.h>
#include "darray_generic.h"
void destroyPoint (void *_elem, void *context);
void printPoint (void *_elem);
int  comparePoints(void *_elemA, void *_elemB);
typedef struct 
{
    int x;
    int y;
}point_t;

int main()
{   darray* ptrDarr;
    int item,i,index,numOfItems,j=0;
    size_t initial_capacity;
    void *  elem;
    FILE* fp;
    point_t* pointAdd;
    point_t* pointGet;
    void* pointRem;
    elementDestroy destroyFunc=destroyPoint;
    elementPrinte printeFunc=printPoint;
    elementCompare comp=comparePoints;
    fp=fopen("fileDet.txt","a");
    if((fp)==NULL)
    {
        return 0;
    }

    printf("Enter initial_capacity\n");
    scanf("%lu",&initial_capacity); 
    darrayCreate(&ptrDarr, initial_capacity);
   
      do 
       {
           pointAdd=malloc(sizeof(point_t));
           printf("Enter x\n");
           scanf("%d",&(pointAdd->x)); 
           printf("Enter y\n");
           scanf("%d",&(pointAdd->y)); 
            if(pointAdd->x==-1)
                break;
           darrayAdd(ptrDarr,pointAdd);
           

       } while(pointAdd->x!=-1) ;

    
    printDarray(ptrDarr,printeFunc);
  
    pointRem=(point_t*)malloc(sizeof(point_t));    
    darrayDelete(ptrDarr,&pointRem);
    printDarray(ptrDarr,printeFunc);

   
    darrayItemsNum(ptrDarr,&numOfItems);
    printf("num of items=%d\n",numOfItems);

    printf("Enter index to get\n");
    scanf("%d",&index); 
    darrayGet(ptrDarr, index, (void**)&pointGet);
    printf("geted item x=%d\n",pointGet->x);
     printf("geted item y=%d\n",pointGet->y);


     pointAdd=malloc(sizeof(point_t));
           printf("Enter x to set\n");
           scanf("%d",&(pointAdd->x)); 
           printf("Enter y to set\n");
           scanf("%d",&(pointAdd->y)); 

    printf("Enter index to set\n");
    scanf("%d",&index); 
    drraySet(ptrDarr, index,pointAdd);
    printf("Array after set:\n");
    printDarray(ptrDarr,printeFunc);

   
    darraySort(ptrDarr,comp);
    printf("Sorted array is:\n");
    printDarray(ptrDarr,printeFunc);
   darrayDestroy(ptrDarr, destroyFunc, fp);
    fclose(fp);
    return 0;
}

void destroyPoint (void *_elem, void *context)
{ FILE* fp=(FILE*)context;
 point_t* p=(point_t*)_elem;
    fprintf(fp,"x= %d ",p->x);
    fprintf(fp,"y= %d ",p->y);
     free(p);
}

void printPoint (void *_elem)
{
    point_t* p=(point_t*)_elem;
    printf("x= %d ",p->x);
    printf("y= %d ",p->y);

}

 int  comparePoints(void *_elemA, void *_elemB)
{   point_t* pA=(point_t*)_elemA;
    point_t* pB=(point_t*)_elemB;
    int res=(pA->x+pA->y)-(pB->x+pB->y);
    return res;
}
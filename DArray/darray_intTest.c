#include <stdlib.h>
#include <stdio.h>
#include "darray_int.h"

int main()
{   darray* ptrDarr;
    int item,i,index;
    size_t initial_capacity;
    printf("Enter initial_capacity\n");
    scanf("%lu",&initial_capacity); 
    darrayCreate(&ptrDarr, initial_capacity);
    do
    {
        printf("Enter item to add\n");
        scanf("%d",&item); 
        darrayAdd(ptrDarr,item);
    } while(item !=-1);
   
   /*for(i =0 ; i<initial_capacity;i++)
        {printf("Enter item to delete\n");
        scanf("%d",&item); 
        darrayDelete(ptrDarr,&item);
      }*/
    printf("Enter index to get\n");
    scanf("%d",&index); 
    darrayGet(ptrDarr, index, &item);
    printf("item = %d\n",item);
    printf("Enter index to set\n");
    scanf("%d",&index); 
    /*drraySet(ptrDarr, index,item);
    darrayGet(ptrDarr, index, &item);
    printf("%d\n",item);*/
    darraySort(ptrDarr);
    printDarray(ptrDarr);
    

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "darray_generic.h"
struct darray
{   size_t initial_capacity;
    size_t capacity;
    size_t index;
    void ** arr;

};
/*static void quicksort(darray* dArr,elementCompare comp){
int i, j, pivot, temp;
if(comp(first,last)<0){
pivot=first;
i=first;
j=last;
while(i<j){
while(number[i]<=number[pivot]&&i<last)
i++;
while(number[j]>number[pivot])
j--;
if(i<j){
temp=number[i];
number[i]=number[j];
number[j]=temp;
}
}
temp=number[pivot];
number[pivot]=number[j];
number[j]=temp;
quicksort(number,first,j-1);
quicksort(number,j+1,last);
}
}
int main(){
int i, count, number[25];
printf("Enter some elements (Max. - 25): ");
scanf("%d",&count);
printf("Enter %d elements: ", count);
for(i=0;i<count;i++)
scanf("%d",&number[i]);
quicksort(number,0,count-1);
printf("The Sorted Order is: ");
for(i=0;i<count;i++)
printf(" %d",number[i]);
return 0;
}*/
AdtStatus printDarray(darray *dArr,elementPrinte printFunc)
{   int i;
     if( (dArr)==NULL)
    {
        return   AllocationError;
        
    }  
    for(i=0;i<dArr->index;i++)
    {
        printFunc(dArr->arr[i]);
    }
    printf("\n");
    return  OK;
}

AdtStatus darrayCreate(darray** dArr, size_t initial_capacity)
{

    *dArr=malloc(sizeof(darray));
    if( (*dArr)==NULL)
    {
        return   AllocationError;
        
    }  
    (*dArr)->arr=malloc((initial_capacity)*sizeof(void*));
      if( (*dArr)->arr==NULL)
    {   free(*dArr);
        return   AllocationError;
        
    }  
    (*dArr)->index=0;
    (*dArr)->capacity=initial_capacity;
    (*dArr)->initial_capacity=initial_capacity;
     return  OK;
}

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void* context)
{   int i=0;
     if( dArr==NULL)
    {
        return   AllocationError;
        
    } 
    for(i=0;i<dArr->index;i++)
    {
        destroyFunc(dArr->arr[i],context);
    }
    free(dArr->arr);
    free(dArr);
    return  OK;
}

AdtStatus   darrayAdd(darray *dArr,  void  *_item)
{   void** temp;
    if(dArr==NULL)
        return   AllocationError;
    if(dArr->index==dArr->capacity)
    {
        temp=realloc(dArr->arr,dArr->capacity*2*sizeof(void*));
    
        if(temp!=NULL)
        {
            dArr->arr=temp;
            dArr->capacity*=2;
        }
        else 
            return   AllocationError;
    }
    dArr->arr[dArr->index]=_item;
    dArr->index++;
    return  OK;
}

AdtStatus   darrayDelete(darray *dArr,  void** _item)
{   void** temp;
     if(dArr==NULL)
        return   AllocationError;
    if(dArr->index==0)
      return   WrongIndex;
    dArr->index--;
      if(dArr->index==(size_t)(0.75*((dArr->capacity)/2 ))&& (dArr->capacity)>(dArr->initial_capacity))
    {
        temp=realloc(dArr->arr,(dArr->capacity/2)*sizeof(void*));
    
        if(temp!=NULL)
        {
            dArr->arr=temp;
            dArr->capacity=dArr->capacity/2;
        }
        else 
            return   AllocationError;
      }
    *_item=dArr->arr[dArr->index];
    return  OK;
}

AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item)
{
     if(dArr==NULL)
        return   AllocationError;
      if(dArr->index<_index) 
       return   WrongIndex;
     *_item=dArr->arr[_index];
      return  OK;
}

AdtStatus   drraySet(darray *dArr, size_t _index, void*  _item)
{

    if(dArr==NULL)
        return   AllocationError;
    if(dArr->index<_index) 
       return   WrongIndex;
    free(dArr->arr[_index]);
    dArr->arr[_index]=_item;
    return  OK; 
}

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
    if(dArr==NULL)
        return   AllocationError;
   * _numOfItems=dArr->index;
    return  OK; 
    
}

/*AdtStatus darraySort(darray *dArr,elementCompare comp)
{   int i,temp,swap=0,j=0;
     if(dArr==NULL)
        return   AllocationError;
  
    quicksort(dArr->arr, comp);
   return  OK;  
}*/

#include <iostream>
#include <string.h>
#include "memPage.h"
#include "memoryMan.h"
#include "memPool.h"

void memTest(memManager_t* mm)
{
  int k=4;
  long z=6;
  int w=8;
  cout<<"the size actual :"<<mm->getActualSize()<<endl;
  mm->writeM(&k,sizeof(int));
  mm->readM(&k,sizeof(int),0);
  cout<<"the number"<<k<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
  mm->writeM(&z,sizeof(long));
  mm->readM(&z,sizeof(long),3);
  cout<<"the number"<<z<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
  mm->writeM(&w,sizeof(int));
  mm->readM(&w,sizeof(int),5);
  cout<<"the number"<<w<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
  try{
      mm->setCurrent(10);
     }catch(...)
     {
       cout<<"can't setCurrent:"<<endl; 
     };
}

int main(){
memManager_t* mm;
int ans;
  cout<<"enter 1 to pool test or 2 to page test"<<endl;
  cin>>ans;
  if(ans==1)
    mm=new  memPool_t;
  else if(ans==2)
    mm=new  memPage_t;
  else 
    cout<<"error:"<<endl;
    try{
        memTest(mm);
      }catch (std:: bad_alloc){
        cout<<"bad alloc:"<<endl; 
      };

  
}   
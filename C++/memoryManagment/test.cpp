#include <iostream>
#include <string.h>
#include "memPage.h"
#include "memoryMan.h"


int main(){

  memPage_t p;
  int k=4;
  int z=4;
  int w=8;
  cout<<"the size actual :"<<p.getActualSize()<<endl;
  cout<<"the size capacity :"<<p.getCapacity()<<endl;
  p.writeM(&k,sizeof(int));
  p.readM(&k,sizeof(int),0);
  cout<<"the number"<<k<<endl;
  cout<<"the index:"<<p.getCurrent()<<endl;
  p.writeM(&z,sizeof(int));
  p.readM(&z,sizeof(int),4);
  cout<<"the number"<<z<<endl;
  cout<<"the index:"<<p.getCurrent()<<endl;
  p.writeM(&w,sizeof(int),2);
  p.readM(&w,sizeof(int),2);
  cout<<"the number"<<w<<endl;
  cout<<"the index:"<<p.getCurrent()<<endl;

  

}   
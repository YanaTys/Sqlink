#include <iostream>
#include <string.h>
#include <vector>
#include "memPage.h"
#include "memPool.h"


size_t  memPool_t::readM(void *k,size_t nOfByte)
{ size_t nOfB=0;
  int i=this->getCurrent();
  char * temp=(char *)k;
  while(nOfB!= nOfByte)
  {
      if(i>this->v.size()-1)
        break;
      nOfB+=v[i]->readM(temp+nOfB,nOfByte-nOfB);
      i++;
  }
  return nOfB;
}

size_t  memPool_t::readM(void *k,size_t nOfByte,size_t pos)
{ size_t nOfB=0;
  int i=pos;
  char * temp=(char *)k;
  if(pos>v.size())
    return 0;
  while(nOfB!= nOfByte)
  {
      if(i>this->v.size()-1)
        break;
      nOfB+=v[i]->readM(temp+nOfB,nOfByte-nOfB);
      i++;
  }
  return nOfB;
}

 size_t memPool_t::writeM(const void * k,size_t nOfByte)
 {
  size_t nOfB=0;
  size_t pos;
  int i=this->getCurrent();
  char * temp=(char *)k;
  
  while(nOfB!= nOfByte)
  {
      if(i>(this->v.size()-1))
      {
          memPage_t * page = new memPage_t;
          v.insert(v.end(), page);
      }
      if(v[i]->getCurrent()==0)
        pos=v[i]->getCurrent();
      else 
        pos=v[i]->getCurrent()+1;
      nOfB+=v[i]->writeM(temp+nOfB,nOfByte-nOfB,pos);
      i++;
      
  }
if(v.size()!=1)
    this->setActualSize((v.size()-2)*v[0]->getCapacity()+v[v.size()-1]->getActualSize());
  else
    this->setActualSize(v[0]->getActualSize());
  this->setCurrent(--i);
  
  return nOfB;
}
 
 size_t memPool_t::writeM(const void * k,size_t nOfByte,size_t pos)
 {
  size_t nOfB=0;
  size_t p;
  int i=pos;
  char * temp=(char *)k;
  if(pos>v.size())
    return 0;
  while(nOfB!= nOfByte)
  {
      if(i>this->v.size()-1)
      {
          memPage_t * page = new memPage_t;
          v.insert(v.end(), page);
      }
      if(v[i]->getCurrent()==0)
        p=v[i]->getCurrent();
      else 
        p=v[i]->getCurrent()+1;
      nOfB+=v[i]->writeM(temp+nOfB,nOfByte-nOfB,p);
      i++;
      this->setCurrent(i);
  }
  if(v.size()!=1)
    this->setActualSize((v.size()-2)*v[0]->getCapacity()+v[v.size()-1]->getActualSize());
  else
    this->setActualSize(v[0]->getActualSize());
 this->setCurrent(--i);
  return nOfB;
}
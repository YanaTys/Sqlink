#include <iostream>
#include <string.h>
#include "memPage.h"

size_t memPage_t::readM(void *k,size_t nOfByte){

  if(this->getCurrent() + nOfByte > this->getActualSize()){

    nOfByte=this->getActualSize()-this->getCurrent();

  }
  memcpy(k,this->m_p+this->getCurrent(),nOfByte);
  return nOfByte;
}

size_t memPage_t::readM(void *k,size_t nOfByte,size_t pos)
  { if(pos > this->getActualSize())
      return 0;

  if(pos + nOfByte > this->getActualSize()){

    nOfByte=this->getActualSize()-pos;

  }
  memcpy(k,this->m_p+pos,nOfByte);
  return nOfByte;
}

size_t memPage_t::writeM(const void * k,size_t nOfByte)
{

  if(this->getCurrent() + nOfByte > this->m_capacity){
    nOfByte=this->m_capacity-this->getCurrent();
    this->setActualSize(this->m_capacity);
    }
  else if(this->getCurrent()+nOfByte>this->getActualSize()){
       this->setActualSize(this->getCurrent()+nOfByte);


  }
  if(this->getCurrent()!=0){
    memcpy(this->m_p+this->getCurrent()+1,k,nOfByte);  
  }
  memcpy(this->m_p+this->getCurrent(),k,nOfByte);
  this->setCurrent(this->getCurrent()+nOfByte-1);
  
  return nOfByte;

}

size_t memPage_t::writeM(const void * k,size_t nOfByte,size_t pos){
 if(pos-1>this->getActualSize()&&pos!=0){
   return 0;
 } 
   if(pos + nOfByte > this->m_capacity){
     nOfByte=this->m_capacity-pos;
     this->setActualSize(this->m_capacity);
   }
   else if(pos+nOfByte>this->getActualSize()){
        this->setActualSize(pos+nOfByte);

   }
  memcpy(this->m_p+pos,k,nOfByte);
  this->setCurrent(this->getCurrent()+nOfByte-1);
  return nOfByte;


}
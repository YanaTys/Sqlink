#pragma once
# include <iostream>
#include <string.h>
#include "memoryMan.h"


class memPage_t: public memManager_t{
   public:
      ~memPage_t(){};
      memPage_t(){
           m_capacity=6;
           m_p=new char [6];
      }
      memPage_t(size_t capacity){
           m_capacity=capacity;
      }
      size_t getCapacity()const{return m_capacity;};
      bool isFull(){
       if(this->getActualSize()==m_capacity){
           return true;
       }
       return false;
    }
    virtual size_t readM(void *k,size_t nOfByte);
    virtual size_t readM(void *k,size_t nOfByte,size_t pos);
    virtual size_t writeM(const void * k,size_t nOfByte);
    virtual size_t writeM(const void * k,size_t nOfByte,size_t pos);
    
    


  private:
     size_t m_capacity;
     char * m_p;
     memPage_t(const  memPage_t & mem){};
     memPage_t& operator= (const  memPage_t& mem){};
     

};

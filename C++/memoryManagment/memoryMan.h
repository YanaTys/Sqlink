#pragma once
# include <iostream>
#include <string.h>
using namespace std;
class memManager_t{
  public:
   virtual ~memManager_t(){};
    memManager_t(){
        m_actualSize=0;
        m_current=0;
        
    };
    size_t getCurrent()const{return m_current;};
   void setCurrent(size_t cur){
    
        if(m_actualSize>=cur){
             m_current=cur;
        }
        else
          throw  -1;
    };
    bool isEmpty(){
       if(m_actualSize!=0){
           return false;
       }
       return true;
    }
    size_t getActualSize()const{return m_actualSize;};
    virtual size_t readM(void *k,size_t nOfByte)=0;
    virtual size_t readM(void *k,size_t nOfByte,size_t pos)=0;
    virtual size_t writeM(const void * k,size_t nOfByte)=0;
    virtual size_t writeM(const void * k,size_t nOfByte,size_t pos)=0;
    
    
  protected:
      
    void setActualSize(size_t actualSize){m_actualSize=actualSize;};

    


  private:
     memManager_t(const  memManager_t & mem){};
     memManager_t& operator= (const  memManager_t& mem){};
     size_t m_actualSize;
     size_t m_current;
     


};

 
#pragma once
# include <iostream>
#include <string.h>
#include <vector>
#include "memoryMan.h"
#include "memPage.h"


class memPool_t: public memManager_t{
   public:
      ~memPool_t(){
        int i;
            for(i=0;i<v.size();i++){
               delete v[i];
            }
      };
      memPool_t(){
         memPage_t * page=new memPage_t;
         v.insert(v.end(), page);
         	
          
      }
     
    virtual size_t readM(void *k,size_t nOfByte);
    virtual size_t readM(void *k,size_t nOfByte,size_t pos);
    virtual size_t writeM(const void * k,size_t nOfByte);
    virtual size_t writeM(const void * k,size_t nOfByte,size_t pos);
    
    


  private:
     vector<memPage_t*> v; 
     memPool_t(const  memPool_t & mem){};
     memPool_t& operator= (const  memPool_t& mem){};
     

};

 
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
         memPage_t * page=new page_t;
         v.insert(v.end(), page);	
          
      }
     
    virtual size_t readM(void *k,size_t nOfByte)const;
    virtual size_t readM(void *k,size_t nOfByte,size_t pos)const;
    virtual size_t writeM(const void * k,size_t nOfByte);
    virtual size_t writeM(const void * k,size_t nOfByte,size_t pos);
    
    


  private:
     vector<Page_t*> v; 
     memPool_t(const  memPool_t & mem){};
     memPool_t& operator= (const  memPool_t& mem){};
     

}
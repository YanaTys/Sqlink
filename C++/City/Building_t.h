#pragma once
# include <iostream>
#include <string.h>
using namespace std;

template <class TID>

class building_t{
  public:
    ~building_t(){};
    building_t();
    building_t(const  building_t & bld);
    building_t& operator= (const  building_t& bld);
    TID getBuildingID()const;
    void setBuildingID(TID newId);

  private:
     TID ID;  

};
template <class TID>
building_t<TID>& building_t<TID>:: operator= (const  building_t<TID>& bld)
{
    if(this!=&bld)
    {  
        
        this->ID=bld.ID;
    }
    return *this;
}
template <class TID>
building_t<TID>::building_t(const building_t<TID>& bld)
{   
   
    this->ID=bld.ID;

}
template <class TID>
 building_t<TID>::building_t()
 {
     
 }
template <class TID>
 TID building_t<TID>::getBuildingID() const
 {
     return this->ID; 
 }
template <class TID>
 void building_t<TID>::setBuildingID(TID newId) 
 {
     this->ID=newId;
     
  }
#pragma once
# include <iostream>
#include <string.h>
#include "Building_t.h"
#include <vector>
using namespace std;

template <class TSID,class TID>

class street_t{
  public:
    ~street_t(){};
    street_t();
    street_t(const  street_t & strt);
    street_t& operator= (const  street_t& strt);
    TSID getStreetID()const;
    void setStreetID(TSID newId);
    void AddBuilding2Street(const  building_t<TID>& bld);
    building_t<TID> getBuilding(const  TID bID )const; 

  private:
     TSID SID;  
     vector<building_t<TID> > v;

};

template <class TSID,class TID>
street_t<TSID,TID>& street_t<TSID,TID>:: operator= (const  street_t<TSID,TID>& strt)
{
    if(this!=&strt)
    {  
        
        this->SID=strt.SID;
        this->v=strt.v;
        
    }
    return *this;
}

template <class TSID,class TID>
street_t<TSID,TID>::street_t(const street_t<TSID,TID>& strt)
{   
  
    this->SID=strt.SID;
    this->v=strt.v;


}

template <class TSID,class TID>
 street_t<TSID,TID>::street_t()
 {
     /*building_t <TID>  bild;
     v.insert(v.end(), bild);*/
 }

template <class TSID,class TID>
 TSID street_t< TSID,TID>::getStreetID()const
 {
     return this->SID; 
 }
template <class TSID,class TID>
 void street_t<TSID,TID>::setStreetID(TSID newId) 
 {
     this->SID=newId;
     
  }

  template <class TSID,class TID>
 void street_t<TSID,TID>::AddBuilding2Street(const  building_t<TID>& bld) 
 {
     v.insert(v.end(), bld);
 }

template <class TSID,class TID>
 building_t<TID> street_t<TSID,TID>::getBuilding(const  TID bID) const
 {int i=0;
    for (i=0;i<v.size();i++)
    {
        if(v[i].getBuildingID()==bID)
            return v[i];
    }
     throw i;
 }

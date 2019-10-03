#pragma once
# include <iostream>
#include <string.h>
#include "Street_t.h"
#include <vector>
using namespace std;

template <class TCID,class TSID,class TID>

class city_t{
  public:
    ~city_t(){};
    city_t();
    city_t(const  city_t & ct);
    city_t& operator= (const  city_t& ct);
    TCID getCityID()const;
    void setCityID(TCID newId);
    void AddStreet(const  street_t<TSID,TID>& strt);
    street_t<TSID,TID> getStreet(const  TSID sID )const; 

  private:
     TCID CID;
     vector<street_t<TSID,TID> > v; 
     

};

template <class TCID,class TSID,class TID>
city_t<TCID,TSID,TID>& city_t<TCID,TSID,TID>:: operator= (const  city_t <TCID,TSID,TID> & ct)
{
    if(this!=&ct)
    {  
        
        this->CID=ct.CID;
        this->v=ct.v;
        
    }
    return *this;
}

template <class TCID,class TSID,class TID>
city_t<TCID,TSID,TID>::city_t(const city_t <TCID,TSID,TID> & ct)
{   
  
    this->CID=ct.CID;
    this->v=ct.v;


}

template <class TCID,class TSID,class TID>
 city_t<TCID,TSID,TID>::city_t()
 {
     /*building_t <TID>  bild;
     v.insert(v.end(), bild);*/
 }

template <class TCID,class TSID,class TID>
 TCID city_t<TCID,TSID,TID>::getCityID() const
 {
     return this->CID; 
 }

template <class TCID,class TSID,class TID>
 void city_t<TCID,TSID,TID>::setCityID(TCID newId) 
 {
     this->CID=newId;
     
  }

  template <class TCID,class TSID,class TID>
 void city_t<TCID,TSID,TID>::AddStreet(const  street_t<TSID,TID>& strt) 
 {
     v.insert(v.end(), strt);
 }

template <class TCID,class TSID,class TID>
 street_t<TSID,TID> city_t<TCID,TSID,TID>::getStreet(const  TSID sID) const
 {int i=0;
    for (i=0;i<v.size();i++)
    {
        if(v[i].getStreetID()==sID)
            return v[i];
    }
     throw i;
 }

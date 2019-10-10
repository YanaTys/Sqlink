#pragma once
# include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>
# include <algorithm>
# include <typeinfo>
#include "Equal_t.h"
using namespace std;

template <class T,class C>
class container_t{
    public:
    
    container_t(){};
    ~container_t();
    bool empty()const{return cont.empty();};
    size_t size()const{return cont.size();};
    void push( T* x) { return cont.push_back(x); };
    T*  begin()const{return *cont.begin();};
    T* back()const{return cont.back();};
    T* findIf(const T&  param){itr=find_if(cont.begin(),cont.end(),Equal_t<T>(param));
    if(itr==cont.end())
        return 0;
    return *itr;
    };

    T* removeElem (const T& param)
    { 
    itr=find_if(cont.begin(),cont.end(),Equal_t<T>(param));
    T* paramP = *itr;
    if(itr==cont.end())
        return 0;
    
     cont.erase(itr);
     return paramP;
    };
    

    void removeAllElem ()
    {   itr=cont.begin();  
        while(itr!=cont.end())
        {   cont.erase(itr);
            itr=cont.begin();
        }

    };

bool removeAndDelElem (const T&  param)
    { itr=find_if(cont.begin(),cont.end(),Equal_t<T>(param));
    
    if(itr==cont.end())
        return false;
    
     cont.erase(itr);
     delete *itr;
     return true;
    };
void  removeAndDelAllElem ()
{
        itr=cont.begin();  
        while(itr!=cont.end())
        {   cont.erase(itr);
            delete *itr;
            itr=cont.begin();
        }T
};
T*  operator[] (unsigned int i)
{   vector<T*> v;
    int j=0;
    itr=cont.begin();
    if(typeid(v)==typeid(cont))
        return (*(vector<T*>*)&cont)[i];
   else 
    {
    if(i<cont.size())
        {for(j=0;j<i;j++)
            itr++;
        return *itr;}
    else return 0;
    }
    

    
   private:
    container_t(const  container_t & con){};
    container_t& operator= (const  container_t& con){};
    typedef typename C::iterator iter_t;
    typedef typename C::const_iterator constIter_t;
    iter_t itr;
    constIter_t constItr;
    C cont;

}; 

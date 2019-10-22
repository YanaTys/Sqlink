#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <map>
#include "meeting.h"
using namespace std;

class diary_t
{     public:
      virtual ~diary_t(){};
      diary_t(){};

       bool insert (meeting_t * meet){
        itr=m.begin();
        meeting_t * meetP;
        meeting_t * meetP2;
       if(itr==m.end()){
           m[meet->getBegin()]=meet;
           return true;
       }
       meetP=itr->second;
       if(meet->getEnd()<meetP->getBegin()){
            m[meet->getBegin()]=meet;
           return true;
       }
       itr=m.end();
       itr--;
       meetP=itr->second;
        if(meet->getBegin()>meetP->getEnd()){
            m[meet->getBegin()]=meet;
           return true;
       }
       if(m.size()==1){
           return false;
       }
       itr=m.begin();
       meetP=itr->second;
       itr++;
       meetP2=itr->second;
       while(itr!=m.end())
       {
          if(meet->getBegin() > meetP->getEnd() && meet->getEnd() < meetP2->getBegin()){
               m[meet->getBegin()]=meet;
               return true;
          }
          meetP=itr->second;
          itr++;
          meetP2=itr->second;
       }
       return false;
      };
        meeting_t* findM const(const float& fBegin)
        {  cItr=m.find(fBegin);
          if(cItr==m.end())
                return 0;
          else
               return (cItr->second);
        };
         void clean()
         {
             m.clear();
         };

        bool remove (const float& rBegin)
        {   if(findM(rBegin)==NULL)
                return false;
            else
            {
                m.erase(m.find(rBegin));
                return true; 
            }
        };
        
       

        private:
        map <float ,meeting_t*> m;
        typedef typename map<float ,meeting_t*>::iterator iter_t;
        typedef typename map<float ,meeting_t*>::const_iterator cIter_t;
        iter_t itr;
        cIter_t cItr;
        diary_t(const diary_t& dr);
        diary_t& operator=(const diary_t& dr);


};
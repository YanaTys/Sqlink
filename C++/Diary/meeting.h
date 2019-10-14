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
using namespace std;

class meeting_t{
    public:
         virtual ~meeting_t(){};
         meeting_t(const float& begin,const float& end, string& subj)
         {   int i=-1;
             if(begin<0||begin>=end||end>24)
             throw i;
             else
             {
             m_begin=begin;
             m_end=end;
             m_subj=subj;}
         };
       /* bool operator< (const   meeting_t& meet)const{
         if(this->m_begin<meet.m_begin){
            return true;
        }
         return false;
        };*/
        const float& getBegin()const{return this->m_begin;};
        const float& getEnd()const{return this->m_end;};
        const string& getSubj()const{return this->m_subj;};
 


    private:
    meeting_t(const meeting_t & meet){};
    meeting_t& operator=(const meeting_t & meet){};
    float m_begin;
    float m_end;
    string m_subj;
};
    
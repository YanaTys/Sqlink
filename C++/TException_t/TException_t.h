#pragma once
# include <iostream>
#include <string.h>
using namespace std;

template <class TOBJ>

class tException_t {
  public:
    ~tException_t(){};
    tException_t(TOBJ obj,string fileName,int line,string desc)
    {
        this->m_obj=obj;
        this->m_fileName=fileName;
        this->m_line=line;
        this->m_desc=desc;

    };
    tException_t(const  tException_t & excep){};
    tException_t& operator= (const  tException_t& excep){};

    const TOBJ& getObj()const{ return this->m_obj;};
    const string& getFileName()const{return this->m_fileName;};
    const int& getLine()const{return this->m_line;};
    const string& getDesc()const{return this->m_desc;};

  private:
     TOBJ m_obj;  
     string m_fileName;
     int m_line;
     string m_desc;
};
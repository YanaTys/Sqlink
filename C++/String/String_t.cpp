# include <iostream>
# include <string.h>
#include "String_t.h"
using namespace std;

String_t::String_t(const char * nm)
{   this->str=new char [strlen(nm)+1];
    strcpy(this->str,nm);
}


String_t::String_t()
{   
}

String_t::~String_t()
{   
    delete[](this->str);
}

String_t::String_t(const String_t & st)
{
    this->str=st.str;
}

String_t& String_t:: operator= (const  String_t& st)
{
    if(this!=&st)
    {
        delete[] str;
        this->str=new char [strlen(st.str)+1];
        strcpy(this->str,st.str);


    }
    return *this;
}

 int  String_t::length() const 
 {
     return strlen(this->str);
 }

 void String_t::setString(const char * nm)
 {     
     delete[] str; 
     this->str=new char [strlen(nm)+1];
     strcpy(this->str,nm);
 }
  const char* String_t::getString() const
  {
      return this->str;
  }
   int String_t::compare (const  String_t& st) const
   {
       return strcmp(this->str,st.str);
   }
    void String_t::print() const
    {
        cout<<"the str:"<<this->str<<endl;
    }
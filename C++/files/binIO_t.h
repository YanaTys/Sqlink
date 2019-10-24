#pragma once
# include <iostream>
#include <string.h>
# include <stdio.h>
# include " virtIO_t.h"

using namespace std;

class binIO_t :public virtIO_t
{
    public:
        virtual ~binIO_t(){};
        binIO_t(){};
        binIO_t(const string &name, const string& mode): virtIO_t(name, mode) {};

    virtual binIO_t& operator<<( const int& num){return funcOut(num,"%d"); };
    virtual binIO_t& operator>>( int& num){return funcIn(num,"%d");};
    virtual binIO_t& operator<<( const float& num){return funcOut(num,"%f");};
    virtual binIO_t& operator>>(  float& num){return funcIn(num,"%f");};
    virtual binIO_t& operator<<( const long& num){return funcOut(num,"%l");};
    virtual binIO_t& operator>>(  long& num){return funcIn(num,"%l");};  
    virtual binIO_t& operator<<( const short& num){return funcOut(num,"%h");};
    virtual binIO_t& operator>>(  short& num){return funcIn(num,"%h");};     
    virtual binIO_t& operator<<( const char& num){return funcOut(num,"%c");};
    virtual binIO_t& operator>>(  char& num){return funcIn(num,"%c");};   
    virtual binIO_t& operator<<( const double& num){return funcOut(num,"%lf");};
    virtual binIO_t& operator>>(  double& num){return funcIn(num,"%lf");}; 

    virtual binIO_t& operator<<( const unsigned int&  num){return funcOut(num,"%lu");};
    virtual binIO_t& operator>>( unsigned int& num){return funcIn(num,"%lu");};
    virtual binIO_t& operator<<( const unsigned long& num){return funcOut(num,"%lu");};
    virtual binIO_t& operator>>(  unsigned long& num){return funcIn(num,"%lu");};  
    virtual binIO_t& operator<<( const unsigned short& num){return funcOut(num,"%hu");};
    virtual binIO_t& operator>>(  unsigned short& num){return funcIn(num,"%hu");};     
    virtual binIO_t& operator<<( const unsigned char& num){return funcOut(num,"%u");};
    virtual binIO_t& operator>>(  unsigned char& num){return funcIn(num,"%u");}; 
     binIO_t& operator<<(void* Buf)
     {
         m_leftShift=Buf;
         return *this;
         };
     binIO_t& operator>>(const void* Buf)
     { 
         m_rightShift=(void*)Buf;
         return *this;
    };
    
    void operator,(int len)
     {  int i=1;
         if(m_leftShift!=NULL)
         {    if(this->getMode()!="rb")
                {fwrite(m_leftShift,len,1,fp);
                m_leftShift=0;}
             else if(this->getMode()=="rb")
            {
                this->SetStatus(writeErr_e);
                throw  i;
            }    
             
         }
         else if(m_rightShift!=NULL)
         {   if(this->getMode()!="wb")
                {
                   fread(m_rightShift,len,1,fp);
                    m_rightShift=0; 
                }
              else if(this->getMode()=="wb")
              {
                this->SetStatus(readErr_e);
                throw  i;
              }    
             
         }
     }; 
    
    private:
    binIO_t(const binIO_t& asc);
    binIO_t& operator=(const binIO_t& asc);
    void* m_leftShift;
    void* m_rightShift;

    template <class T>
    binIO_t& funcOut(const T& num,string s)
    {   int i=1; 
        if(this->getStatus()==cant_open_file_e)
            throw  i;
        else if(this->getMode()=="r"||this->getMode()=="rb")
        {
            this->SetStatus(writeErr_e);
            throw  i;
        }    
        fwrite(&num,sizeof(T),1,fp);
        return *this;
    }

    template <class T>
    binIO_t& funcIn(T& num,string s)
    {    int i=1;   
        if(this->getStatus()==cant_open_file_e)
            throw  i;
        else if(this->getMode()=="w"||this->getMode()=="wb")
            {
                this->SetStatus(readErr_e);
                throw  i;
            }
            fread(&num,sizeof(T),1,fp);
            return *this;
    }

};
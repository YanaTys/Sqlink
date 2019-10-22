#pragma once
# include <iostream>
#include <string.h>
# include <stdio.h>
using namespace std;

class asciiIO_t :public virtIO_t
{
    public:
        virtual ~asciiIO_t(){};
        asciiIO_t(){};
        asciiIO_t(const string &name, const string& mode): virtIO_t(name, mode)
        {  int i=1;
        if(mode!="r+"||mode!="w+"||mode!="r"||mode!="w")
          {m_status=bad_access_e;
           throw  i;}
        } ;

    virtual virtIO_t& operator<<( const int& num)=0;
    virtual virtIO_t& operator>>( int& num)=0;
    virtual virtIO_t& operator<<( const float& num)=0;
    virtual virtIO_t& operator>>(  float& num)=0;
    virtual virtIO_t& operator<<( const long& num)=0;
    virtual virtIO_t& operator>>(  long& num)=0;  
    virtual virtIO_t& operator<<( const short& num)=0;
    virtual virtIO_t& operator>>(  short& num)=0;     
    virtual virtIO_t& operator<<( const char& num)=0;
    virtual virtIO_t& operator>>(  char& num)=0;   
    virtual virtIO_t& operator<<( const double& num)=0;
    virtual virtIO_t& operator>>(  double& num)=0; 

    virtual virtIO_t& operator<<( const unsigned int&  num)=0;
    virtual virtIO_t& operator>>( unsigned int& num)=0;
    virtual virtIO_t& operator<<( const unsigned long& num)=0;
    virtual virtIO_t& operator>>(  unsigned long& num)=0;  
    virtual virtIO_t& operator<<( const unsigned short& num)=0;
    virtual virtIO_t& operator>>(  unsigned short& num)=0;     
    virtual virtIO_t& operator<<( const unsigned char& num)=0;
    virtual virtIO_t& operator>>(  unsigned char& num)=0; 

    
    private:
    asciiIO_t(const asciiIO_t_t& asc);
    asciiIO_t& operator=(const asciiIO_t& asc);
    template <class T>
    void funcOut(const T& num,string s)
    {   int i=1; 
        if(this->getStatus()==cant_open_file_e)
            throw int i;
        else if(this->getMode()=="r")
        {
            this->setStatus(writeErr_e);
            throw  i;
        }    
        fprintf(fp,s,num);
    };

    template <class T>
    void funcIn(T& num,string s)
    {    int i=1;   
        if(this->getStatus()==cant_open_file_e)
            throw  i;
        else if(this->getMode()=="w")
            {
                this->setStatus(readErr_e);
                throw  i;
            }
            fscanf(fp,s,num);
    };

};
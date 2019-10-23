#pragma once
# include <iostream>
#include <string.h>
# include <stdio.h>
# include " virtIO_t.h"

using namespace std;

class asciiIO_t :public virtIO_t
{
    public:
        virtual ~asciiIO_t(){};
        asciiIO_t(){};
        asciiIO_t(const string &name, const string& mode): virtIO_t(name, mode) {};

    virtual asciiIO_t& operator<<( const int& num){return funcOut(num,"%d"); };
    virtual asciiIO_t& operator>>( int& num){return funcIn(num,"%d");};
    virtual asciiIO_t& operator<<( const float& num){return funcOut(num,"%f");};
    virtual asciiIO_t& operator>>(  float& num){return funcIn(num,"%f");};
    virtual asciiIO_t& operator<<( const long& num){return funcOut(num,"%l");};
    virtual asciiIO_t& operator>>(  long& num){return funcIn(num,"%l");};  
    virtual asciiIO_t& operator<<( const short& num){return funcOut(num,"%h");};
    virtual asciiIO_t& operator>>(  short& num){return funcIn(num,"%h");};     
    virtual asciiIO_t& operator<<( const char& num){return funcOut(num,"%c");};
    virtual asciiIO_t& operator>>(  char& num){return funcIn(num,"%c");};   
    virtual asciiIO_t& operator<<( const double& num){return funcOut(num,"%lf");};
    virtual asciiIO_t& operator>>(  double& num){return funcIn(num,"%lf");}; 

    virtual asciiIO_t& operator<<( const unsigned int&  num){return funcOut(num,"%lu");};
    virtual asciiIO_t& operator>>( unsigned int& num){return funcIn(num,"%lu");};
    virtual asciiIO_t& operator<<( const unsigned long& num){return funcOut(num,"%lu");};
    virtual asciiIO_t& operator>>(  unsigned long& num){return funcIn(num,"%lu");};  
    virtual asciiIO_t& operator<<( const unsigned short& num){return funcOut(num,"%hu");};
    virtual asciiIO_t& operator>>(  unsigned short& num){return funcIn(num,"%hu");};     
    virtual asciiIO_t& operator<<( const unsigned char& num){return funcOut(num,"%u");};
    virtual asciiIO_t& operator>>(  unsigned char& num){return funcIn(num,"%u");}; 

    
    private:
    asciiIO_t(const asciiIO_t& asc);
    asciiIO_t& operator=(const asciiIO_t& asc);

    template <class T>
    asciiIO_t& funcOut(const T& num,string s)
    {   int i=1; 
        if(this->getStatus()==cant_open_file_e)
            throw  i;
        else if(this->getMode()=="r")
        {
            this->SetStatus(writeErr_e);
            throw  i;
        }    
        fprintf(fp,s.c_str(),num);
        return *this;
    }

    template <class T>
    asciiIO_t& funcIn(T& num,string s)
    {    int i=1;   
        if(this->getStatus()==cant_open_file_e)
            throw  i;
        else if(this->getMode()=="w")
            {
                this->SetStatus(readErr_e);
                throw  i;
            }
            fscanf(fp,s.c_str(),&num);
            return *this;
    }

};
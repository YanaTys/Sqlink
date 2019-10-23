#pragma once
# include <iostream>
#include <string.h>
# include <stdio.h>
using namespace std;

class virtIO_t {
  public:
  typedef enum status{ok_e,cant_open_file_e,bad_access_e,writeErr_e,readErr_e} status;

   virtual ~virtIO_t() {this->close();};
   virtIO_t(){
       m_path='\0';
       m_mode='\0';
       m_status= ok_e;
   };
   virtIO_t( const string &name, const string& mode)
   { 
       open(name,mode);
   };
    void open(const string &name, const string& mode)
   {  int i=1;
      fp=fopen(name.c_str(),mode.c_str()); 
       /*cout<<fp<<endl;*/
      if(fp==NULL)
      {   cout<<fp<<endl; 
          m_status= cant_open_file_e;
          throw  i;
      } 
     else if(mode!="r+"&&mode!="w+"&&mode!="r"&&mode!="w"&&mode!="wb"&&mode!="rb"&&mode!="rb+"&&mode!="wb+")
           {    m_status=bad_access_e;
                 throw  i;
           }
    else {
        m_path=name;
        m_mode=mode;
        m_status= ok_e;
      
        }
        
   };
    void close()
    {
        if(this->getStatus()==ok_e)
            fclose(fp);
    }; 
  const string& getPath ()const { return m_path;};
  const string& getMode ()const {return m_mode;};
  long getLength() const
  {
      long size;
      long prevPos=ftell(fp);
      fseek(fp,0L,SEEK_END);
      size=ftell(fp);
      fseek(fp,prevPos,SEEK_SET);
      return size;
  };
   void setPos(size_t pos)
   { 
       fseek(fp,pos,SEEK_SET);
   };
   long  getPos() const
   {
       return ftell(fp);
   };
   status getStatus()const {return m_status;};
   

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
    virtual virtIO_t& operator<<(const double& num)=0;
    virtual virtIO_t& operator>>(  double& num)=0; 

    virtual virtIO_t& operator<<( const unsigned int&  num)=0;
    virtual virtIO_t& operator>>( unsigned int& num)=0;
    virtual virtIO_t& operator<<( const unsigned long& num)=0;
    virtual virtIO_t& operator>>(  unsigned long& num)=0;  
    virtual virtIO_t& operator<<( const unsigned short& num)=0;
    virtual virtIO_t& operator>>(  unsigned short& num)=0;     
    virtual virtIO_t& operator<<( const unsigned char& num)=0;
    virtual virtIO_t& operator>>(  unsigned char& num)=0; 

    


  protected:
    FILE * fp;
    string m_path;
    string m_mode;
    status m_status;
    void SetStatus(status newStatusFile){ m_status=newStatusFile;};

  private:
    virtIO_t(const virtIO_t& vr);
    virtIO_t& operator=(const virtIO_t& vr);
    
};
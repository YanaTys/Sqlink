# include <iostream>
# include <string.h>
#include "String_t.h"
using namespace std;

String_t::String_t(const char * nm)

{   if(nm==NULL)
    {
       this->str=new char [16];
       str[0]='\0';  
    }
    else
    {
        this->str=new char [strlen(nm)+1];
        strcpy(this->str,nm);
    }
    
}


String_t::String_t()
{   
    this->str=new char [16];
    str[0]='\0';
}

String_t::~String_t()
{   
    delete[](this->str);
}

String_t::String_t(const String_t & st)
{    this->str=new char [strlen(st.str)+1];
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
     if(nm==NULL)
    { 
       this->str=new char [16];
       str[0]='\0';  
    }
    else
    {
        this->str=new char [strlen(nm)+1];
        strcpy(this->str,nm);
    }
 }
  const char* String_t::getString() const
  {
      return this->str;
  }
   int String_t::compare (const  String_t& st) const
   {
       int res;
       res=strcmp(this->str,st.str);
       if(res>0)
            res=1;
       else if (res<0)
            res=2;
       return res;
   }
    void String_t::print() const
    {
        cout<<"the str:"<<this->str<<endl;
    }
    void String_t::upCase()
    {   int i=0;
        for(i=0;i<strlen(this->str);i++)
        {
         this->str[i]=toupper(this->str[i]);  
        }
       
    }
    void String_t::lowCase()
    {
        int i=0;
        for(i=0;i<strlen(this->str);i++)
        {
         this->str[i]= tolower(this->str[i]);  
        }
       
    }
    void String_t::prepend(const char* nm)
    {   char temp[32];
        strcpy(temp,this->str);
        this->setString(nm);
        strcat(this->str,temp);
    }
    void String_t::prepend2(const  String_t& st)
    {   char temp[32];
         strcpy(temp,this->str);
        this->setString(st.str);
        strcat(this->str,temp);
         
    }
    String_t& String_t:: operator+= (const  String_t& st)
{       char temp[254];
        strcpy(temp,this->str);
        strcat(temp,st.str);
        delete[] str;
        this->str=new char [strlen(temp)+1];
        strcpy(this->str,temp);

    return *this;
}
  String_t& String_t:: operator+= (const  char* nm)
{        char temp[32];
        strcpy(temp,this->str);
        strcat(temp,nm);
        delete[] str;
        this->str=new char [strlen(temp)+1];
        strcpy(this->str,temp);

    return *this;
}

int String_t::operator< (const  String_t& st)
{
    int res=strcmp(this->str,st.str);
    if(res<0){
        return 1;
    }else{
        return 0;
    }
}

int String_t::operator> (const  String_t& st)
{
    int res=strcmp(this->str,st.str);
    if(res>0){
        return 1;
    }else{
        return 0;
    }
}
int String_t::operator>=(const  String_t& st)
{
    int res=strcmp(this->str,st.str);
    if(res>=0){
        return 1;
    }else{
        return 0;
    }
}

int String_t::operator<= (const  String_t& st)
{
    int res=strcmp(this->str,st.str);
    if(res<=0){
        return 1;
    }else{
        return 0;
    }
}

int String_t::operator== (const  String_t& st)
{
    int res=strcmp(this->str,st.str);
    if(res==0){
        return 1;
    }else{
        return 0;
    }
}
int String_t::operator!= (const  String_t& st)
{
    int res=strcmp(this->str,st.str);
    if(res!=0){
        return 1;
    }else{
        return 0;
    }
}
int String_t::contains (const char* nm) const 
{
    int i=0,ptostr2=0,ptostr1=0;

    for(i=0;i<strlen(this->str)&&ptostr2<strlen(nm);i++)
    {
        if(this->str[i]==nm[ptostr2]&&ptostr2==0)/*we find str2 first digit in str1 in place i*/
        {
            ptostr1=i;/*place of first digit of str2 in str1*/
        }
       else  if(this->str[i]!=nm[ptostr2]&&ptostr2!=0)/*if the rest of str2 is not like the rest of str1
        we go to the first place of digit of str2 in str1 */
        {
            i=ptostr1;
        }
        if(this->str[i]==nm[ptostr2])
        {
            ptostr2++ ;/* continue search str2 in str1*/
        }
        else
        {
            ptostr2=0;/*go to start of str2*/
        }

    }
    return (ptostr2==strlen(nm))?1:0;
}

ostream& operator<<( ostream& os ,const String_t& st)
{
    os <<st.getString()<<endl;
    return os;
}

istream& operator>>( istream& is , String_t& st)
{   char str1[128];
    is >>str1;
    st.setString(str1);
    return is;
}

 char & String_t::operator[] (unsigned int i) {
     
     return this->str[i]; 
 }
 char String_t::operator[] (unsigned int i) const {
     
     return this->str[i]; 
 }
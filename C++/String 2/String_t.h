#pragma once
# include <iostream>
# include <string.h>
using namespace std;
class String_t{
    public:
         ~String_t();
        String_t();
        String_t(const char * nm);
        String_t(const String_t & st);
        String_t& operator= (const  String_t& st);
        
        int length()const;
        void setString(const char * nm);
        const char* getString() const{ return this->str;};
        int compare (const  String_t& st) ;
        void print() const;
        void upCase();
        void lowCase();
        void prepend(const char* nm);
        void prepend(const  String_t& st);
        String_t& operator+= (const  String_t& st);
        String_t& operator+= (const  char* nm);
        int operator< (const  String_t& st);
        int operator<= (const  String_t& st);
        int operator> (const  String_t& st);
        int operator>= (const  String_t& st);
        int operator== (const  String_t& st);
        int operator!= (const  String_t& st);
        int contains (const char* nm)  ;
        char& operator[] (unsigned int i);
        char operator[] (unsigned int i) const;
        char* operator() (const unsigned int start,const unsigned int count) const;
        static int getSensFlag () {return caseSens;};
        static int setSensFlag (const int sens); 
        static size_t SetCap ( size_t cap); 
        static size_t getSCap ()  {return defcapacity;};
        int firstOcc(char c)const;
        int lastOcc( char c) const;
        static int getNumOfStr () {return numOfStrings;};



    private:
        char* str;
        static size_t defcapacity;
        size_t mycapacity;
        static int caseSens;
        static int numOfStrings;
        static size_t nextPowerOf2(size_t n) ;
        int sensComp(const char* nm)
        {
            int res;
            if(caseSens==1){
                res=strcmp(this->str,nm);
            }
            else{
                res=strcasecmp(this->str,nm);
            }
            return res;
        }

};
ostream& operator<<( ostream& os ,const String_t& st);
istream& operator>>( istream& is , String_t& st);

        
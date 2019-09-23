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
        const char* getString() const;
        int compare (const  String_t& st) const;
        void print() const;
        void upCase();
        void lowCase();
        void prepend(const char* nm);
        void prepend2(const  String_t& st);
        String_t& operator+= (const  String_t& st);
        String_t& operator+= (const  char* nm);
        int operator< (const  String_t& st);
        int operator<= (const  String_t& st);
        int operator> (const  String_t& st);
        int operator>= (const  String_t& st);
        int operator== (const  String_t& st);
        int operator!= (const  String_t& st);
        int contains (const char* nm) const ;
        char& operator[] (unsigned int i);
        char operator[] (unsigned int i) const;
        
    
    private:
        char* str;

};
ostream& operator<<( ostream& os ,const String_t& st);
istream& operator>>( istream& is , String_t& st);
        
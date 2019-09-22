#pragma once
# include <iostream>
# include <string.h>
using namespace std;
class String_t{
    public:
        String_t();
        String_t(const char * nm);
        ~String_t();
        String_t(const String_t & st);
        String_t& operator= (const  String_t& st);
        int length()const;
        void setString(const char * nm);
        const char* getString() const;
        int compare (const  String_t& st) const;
        void print() const;
    private:
        char* str;


};
#pragma once
# include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
template <class T>
class Equal_t{

 public:
 Equal_t(T i):val(i){};

 bool operator()(T* param )const {return *param==val;};
private:
 T val;

};

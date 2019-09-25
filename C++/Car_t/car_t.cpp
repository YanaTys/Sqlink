# include <iostream>
# include <string>
#include "car_t.h"
using namespace std;
int car_t::idAll=1;
size_t car_t::defCap=1500;


 bool car_t::operator< (const  car_t& car)const{
     if(this->cap<car.cap){
         return true;
     }
     return false;
 }

 bool car_t::compareStrings(const  car_t& car){
    int res= this->name.compare(car.name);
    if(res!=0){
        return false;
    }

    return true;
 }
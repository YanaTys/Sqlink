#include <iostream>
#include <string.h>
#include "Building_t.h"
#include "City_t.h"
#include "Street_t.h"

int main ()
{   building_t<int> bld;
    street_t<string,int> strt;
    city_t<int,string,int> ct;
    int bId=15;
    string sId="Avenue";
    string sId2="Marsey";
    int cId=17;

    bld.setBuildingID(bId);
    strt.setStreetID(sId);
    ct.setCityID(cId);

    strt.AddBuilding2Street(bld);
    ct.AddStreet(strt);
    try
    {
        strt.getBuilding(bId);
    }catch (int )
    {
        cout<<"cant find  building "<<bId<<endl;
    }
    try
    {
        ct.getStreet(sId);
    }catch (int )
    {
        cout<<cout<<"cant find street "<<sId<<endl;
    }

    try
    {
        ct.getStreet(sId2);
    }catch (int )
    {
        cout<<"cant find street "<<sId2<<endl;
    }


    return 0;
}
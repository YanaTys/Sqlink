#include <iostream>
#include <string.h>
# include "TException_t.h"
void func1()
{   int obj=12;
    string fl(__FILE__);
    tException_t<int> excep(obj,fl,__LINE__,"ERROR");
     
    throw excep;
}

int main ()
{   
    try
    {   
        func1 ();
    }catch (tException_t<int>& excep)
    {
        cout<<"obj= "<<excep.getObj()<<endl;
        cout<<"fileName= "<<excep.getFileName()<<endl;
        cout<<"line= "<<excep.getLine()<<endl;
        cout<<"desc= "<<excep.getDesc()<<endl;
    }

    return 0;
}


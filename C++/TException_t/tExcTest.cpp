#include <iostream>
#include <string.h>
#include "TException_t.h"

int main ()
{   tException_t<int> excep(12,__FILE__,__LINE__,"ERROR");
    try
    {
        throw (excep);
    }catch (tException_t<int>& excep)
    {
        cout<<"obj= "<<excep.getObj()<<endl;
        cout<<"fileName= "<<excep.getFileName()<<endl;
        cout<<"line= "<<excep.getLine()<<endl;
        cout<<"desc= "<<excep.getDesc()<<endl;
    }

    return 0;
}

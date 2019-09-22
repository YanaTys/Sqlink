# include <iostream>
# include <string.h>
#include "String_t.h"
using namespace std;

int main()
{   const char str [10]="Abc deF";
    char str2[20];
    int comp;
    String_t st(str);
    st.print();
    st.setString("knfg");
    strcpy(str2,st.getString());
    cout<<"after set :"<<str2<<endl;
    cout<<"len after set :"<<st.length()<<endl;
    comp=st.compare("knfg");
    cout<<"the winner is:"<<comp<<endl;

    return 0;
}
# include <iostream>
# include <string.h>
#include "String_t.h"
using namespace std;

int main()
{   const char str [10]="abc";
    char str2[20];
    char c;
    String_t temp(str);
    int comp;
    String_t st(str);
    st.print();
    cout<<st;
    cin>>temp;
    cout<<temp;
     if(temp<st){
        cout<<"small"<<endl;
    }else if(temp>st){
        cout<<"big"<<endl;
    }else if(temp==st){
        cout<<"equal"<<endl;
    }
    st.setString("knfg");
    strcpy(str2,st.getString());
    cout<<"after set :"<<str2<<endl;
    cout<<"len after set :"<<st.length()<<endl;
    comp=st.compare("knfg");
    cout<<"the winner is:"<<comp<<endl;
    st.prepend("yana");
    cout<<st;
    st.prepend(temp);
    cout<<st;
    temp+=temp;
    cout<<temp;
    temp+="abc";
    cout<<temp;
    st.upCase();
    cout<<st;
    st.lowCase();
    cout<<st;
    cout<<"contains: "<<st.contains ("aB")<<endl;
    temp[0]='z';
    cout<<temp;
    c=temp[0];
    cout<<"c="<<c<<endl;

    
    return 0;
}
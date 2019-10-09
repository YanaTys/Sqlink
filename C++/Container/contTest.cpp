# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <list>
# include <iterator>
# include "Equal_t.h"
# include "Container_t.h"
template <class T,class C >
void testFunc(container_t<T ,C> * c);

int main()
{     int choose=0;
          cout<<"enter 1 to build a vector or 2 to bulid a list or any other number to exit "<<endl;
          cin>>choose;
          switch(choose)
          {
                case 1:
                {
                container_t< int ,vector < int *> > *cont=new container_t< int ,vector< int *> >();
                testFunc <int , vector <int *> >(cont);
                break;
              
                }
                case 2:
                { 
                 container_t< int ,list <int *>  > *cont=new container_t< int ,list <int *>  >();
                 testFunc <int , list <int *> >(cont);
                break;
                }
                default: break;
               
          }
          
         return 0;

}

template <class T,class C >
void testFunc(container_t<T ,C> * c)
{
         int choose=0;
         while(choose!=-1){
          cout<<"enter 1 to push"<<endl;
          cout<<"enter 2 to remove element "<<endl;
          cout<<"enter 3 to remove and delete element "<<endl;
          cout<<"enter 4 to remove all elements "<<endl;
          cout<<"enter 5 to remove and delete all elements "<<endl;
          cout<<"enter 6 to get number of elements "<<endl;
          cout<<"enter 7 to get first element "<<endl;
          cout<<"enter 8 to get last element "<<endl;
          cout<<"enter 9 to  empty function  "<<endl;
          cout<<"enter 10 to operator [] "<<endl;
          cout<<"enter 11 to find element "<<endl;
          cout<<"enter other number to exit "<<endl;
          cin>>choose;
          switch(choose){
              case 1: {
                
                T * elemP = new int;
                cout<<"enter an elem "<<endl;
                 cin>>*elemP;
                
                c->push(elemP);
                break;
              
              }
               case 2: {
                T elem;
                cout<<"enter an elem to remove"<<endl;
                cin>>elem;
                T* elemP =c->removeElem(elem);
                if(elemP==0){
                  cout<<"not found "<<endl;
                }else{
                    cout<<"you  remove : "<<*elemP<<endl;
                }
                break;
                }
                
                case 3: {
                T elem;
                cout<<"enter an elem to remove and delete"<<endl;
                cin>>elem;
                bool ans =c->removeAndDelElem(elem);
                if(ans== false){
                  cout<<"not found can't delete"<<endl;
                }else{
                    cout<<"you remove and delete the element"<<endl;
                }
                break;
                }
                case 4: {

                  c->removeAllElem();

                break;
                }
                 case 5: {
                   c->removeAndDelAllElem();
                break;
                }
                 case 6: {
                  cout<<"number of elemnts : "<<c->size()<<endl;
                break;
                }
                 case 7: {
                cout<<"the first element is: "<<*(c->begin())<<endl;
                break;
                }
                 case 8: {
                  cout<<"the last element is: "<<*(c->back())<<endl;
                
                break;
                }
                 case 9: {
                if(c->empty()==true){
                  cout<<" empty "<<endl;
                }else{
                    cout<<"not empty "<<endl;
                }
                break;
                }
                case 10: {
                unsigned int i;
                T * elemP;
                   int flag=0;
                cout<<"enter an index of elem "<<endl;
                cin>>i;
                if((*c)[i]!=NULL)
                  cout<<"the i elem in container is: "<<*((*c)[i])<<endl;  
                else cout<<"incorect index"<<endl; 
                break;
                }
                case 11: {
                   T elem;
                   T * elemP;
                cout<<"enter an elem to find "<<endl;
                cin>>elem;
                elemP=c->findIf(elem);
                if(elemP==0)
                {
                  cout<<"not in container"<<endl;
                }
                else
                {
                    cout<<"find a "<<*elemP<<endl;
                }
                break;
                }
                default: break;
          }
          
          
      }
    
      }
    

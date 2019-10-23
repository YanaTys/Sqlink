
#include <iostream>
#include <string.h>
#include <stdio.h>
#include " virtIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"
using namespace std;
void testFunc(virtIO_t * vr);

int main()
{     int choose=0;
            string path;
            string mode;
            cout<<"enter path"<<endl;
            cin>>path;
            cout<<"enter mode"<<endl;
            cin>>mode;
          cout<<"enter 1 to asciiIO file or 2 to binaryIO file or other number to end"<<endl;
          cin>>choose;
          virtIO_t * vr;
            
          switch(choose)
          {
                case 1:
                {
                try{    
                        vr=new asciiIO_t(path,mode); 
                        testFunc(vr);     
                }
                  catch(int) {cout<<"can't open file"<<endl;}
                
                break;
                }
          
                case 2:
                { 
                   
                try{
                        vr=new binIO_t(path,mode);
                         testFunc(vr);
                   } catch(int) {cout<<"can't open file"<<endl;};
                break;
                }
                default: break;
               
          }
          
         return 0;
}

void testFunc(virtIO_t * vr)
{
         int choose=0;
         while(choose!=-1){
          cout<<"enter 1 to close"<<endl;
          cout<<"enter 2 to get path "<<endl;
          cout<<"enter 3 to get mode"<<endl;
          cout<<"enter 4 to get length "<<endl;
          cout<<"enter 5 to get position "<<endl;
          cout<<"enter 6 to set position"<<endl;
          cout<<"enter 7 to  get status "<<endl;
          cout<<"enter 8 to operaenter <<"<<endl;
          cout<<"enter 9 to operator>>"<<endl;
          cout<<"enter 10 to operaenter << and ,"<<endl;
          cout<<"enter 11 to operator>> and ,"<<endl;
          
          cout<<"enter -1 to exit "<<endl;
          cin>>choose;
          
          switch(choose){
              case 1: {
                if(vr->getStatus()==0)
                    vr->close();
                else 
                    cout<<"null pointer!"<<endl;
                break;
              
              }
               case 2: {
                if(vr->getStatus()==0)
                    {string path=vr->getPath();
                    cout<<"path= "<<path<<endl;}
                else 
                    cout<<"null pointer!"<<endl;
                break;
               
                }
                
                case 3: {
                 if(vr->getStatus()==0)
                {   string mode=vr->getMode();
                    cout<<"mode= "<<mode<<endl;}
                else 
                    cout<<"null pointer!"<<endl;
                break;
                }
                case 4: {
                if(vr->getStatus()==0)
                {long len=vr->getLength();
                    cout<<"length= "<<len<<endl;}
                else  {
                    cout<<"null pointer!"<<endl;}
                break;
                }
                 case 5: {
                  
                if(vr->getStatus()==0)
                {long pos=vr->getPos();
                    cout<<"pos= "<<pos<<endl;}
                else 
                    cout<<"null pointer!"<<endl;
                
                break;
                }
                 case 6: {
                 if(vr->getStatus()==0)
                { long pos;
                  cout<<"enter position"<<endl;
                  cin>>pos;
                   vr->setPos(pos);}
                else 
                    cout<<"null pointer!"<<endl;
                
                break;
                }
                 case 7: {
                if(vr->getStatus()==0)
                    {
                    cout<<"status= "<<vr->getStatus()<<endl;}
                else 
                    cout<<"null pointer!"<<endl;
                    break;
                }
              
                 case 8: {
               if(vr->getStatus()==0){
                   int num;
                   cout<<"enter num"<<endl;
                   cin>>num;
                   *vr<<num;
                }else{
                    cout<<"null pointer! "<<endl;
                }
                break;
                }
                case 9: {
                if(vr->getStatus()==0){
                 int num=0;  
                   *vr>>num;
                    cout<<"num="<<num<<endl;
                }else{
                    cout<<"null pointer! "<<endl;
                }
                break;
                }
                 case 10: {
                
               if(vr->getStatus()==0){

                   int num;
                   int len;
                   cout<<"enter num"<<endl;
                   cin>>num;
                   cout<<"enter len"<<endl;
                   cin>>len; 
                   *vr<<num,len;
                }else{
                    cout<<"null pointer! "<<endl;
                }
                break;
                }
                case 11: {
                if(vr->getStatus()==0){
                 int num=0;
                 int len=0;
                 cout<<"enter len"<<endl;
                 cin>>len;  
                   *vr>>num,len;
                    cout<<"num="<<num<<endl;
                }else{
                    cout<<"null pointer! "<<endl;
                }
                break;
                }
                
                default: break;
                
          }
          
          
      }
    
}
    


# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <list>
# include <map>
# include <iterator>
# include "meeting.h"
# include "diary.h"
using namespace std;

void testFunc(diary_t& dr);

int main()
{     
    int i=0;   
    diary_t dr;
    testFunc (dr);      
         return 0;

}


void testFunc(diary_t& dr)
{
         int choose=0;
          while(choose!=-1){
            cout<<"enter 1 to insert meeting"<<endl;
            cout<<"enter 2 to find meeting"<<endl;
            cout<<"enter 3 to remove meeting"<<endl;
            cout<<"enter 4 to clean all meetings"<<endl;
            cout<<"enter -1 to exit "<<endl;
            cin>>choose;
            switch(choose){
                case 1: {
                  bool ans;
                  float beginH;
                  float endH;
                  string subj="";
                  cout<<"enter begin of meeting"<<endl;
                  cin>>beginH;
                  cout<<"enter end of meeting"<<endl;
                  cin>>endH;
                  cout<<"enter subject of meeting"<<endl;
                  cin>>subj;
                  meeting_t * meetP;
                  try{
                     meetP = new meeting_t(beginH,endH,subj);
                    }catch(int i){
                      cout<<"cant create this meeting!"<<endl;
                      break;
                    }
                  /*meeting_t * meetP = new meeting_t(beginH,endH,subj);*/
                  ans=dr.insert(meetP);
                  if(ans==true)
                      cout<<"the insert was succsessful"<<endl;
                  else
                  cout<<"can't insert this meeting"<<endl;
                  break;
                
                }
                case 2: {
                  float beginH;
                  cout<<"enter begin of meeting you want to find"<<endl;
                  cin>>beginH;
                  meeting_t * meetP=dr.findM(beginH);
                  if(meetP==0){
                    cout<<"not found "<<endl;
                  }else{
                      cout<<"the meeting in diary"<<endl;
                  }
                  break;
                  }
                  
                  case 3: {
                  float beginH;
                  cout<<"enter begin of meeting you want to remove"<<endl;
                  cin>>beginH;
                  meeting_t * meetP=dr.findM(beginH);
                  bool ans =dr.remove(beginH);
                  if(ans==false){
                    cout<<"not found "<<endl;
                  }else{
                      cout<<"the meeting removed from diary"<<endl;
                      delete meetP;
                  }
                  break;
                  }
                  case 4: {
                  dr.clean();
                  break;
                  }
                  default: break;
            }  
      }
    
 }
   

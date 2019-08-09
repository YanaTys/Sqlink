#include <stdio.h>
#include <string.h>

void squeeze(char*,char*);
int location(char*,char*);
int main ()
{   char str1[10],str2 [10];
    printf ("Enter Str1\n");
    scanf ("%s",str1);
    printf ("Enter Str2\n");
    scanf ("%s",str2);
    //squeeze(str1,str2);
    printf("The first place of str2 in str1 is %d\n",location(str1,str2));
    return 0;
}

void squeeze(char* str1,char* str2)
{ int i=0,j=0,k=0,flag=0;
    for(i=0;i<strlen(str2);i++)
    {
           for(j=0;j<strlen(str1);j++)
        {  flag=0;
           if(str1[j]== str2[i])
           { //str1[j]='*';
               for(k=j;str1[k]!='\0';k++)
               {
                   str1[k]=str1[k+1];
               }
               flag=1;
               }
            if(flag==1)
            {
              j=j-1;
            }
           }

        }

   printf("%s\n",str1);
    return;
}

int location(char* str1,char* str2)
{
    int i=0,ptostr2=0,ptostr1=0;
    for(i=0;i<strlen(str1)&&ptostr2<strlen(str2);i++)
    {
        if(str1[i]==str2[ptostr2]&&ptostr2==0)//we find str2 first digit in str1 in place i
        {
            ptostr1=i;//place of first digit of str2 in str1
        }
       else  if(str1[i]!=str2[ptostr2]&&ptostr2!=0)//if the rest of str2 is not like the rest of str1 we go to the first place of digit of str2 in str1
        {
            i=ptostr1;
        }
        if(str1[i]==str2[ptostr2])
        {
            ptostr2++ ;// continue search str2 in str1
        }
        else
        {
            ptostr2=0;//go to start of str2
        }

    }
    return (ptostr2==strlen(str2))?ptostr1:-1;
}






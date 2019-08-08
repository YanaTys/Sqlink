#include <stdio.h>
#include <string.h>
#include <math.h>

int MyStrComp(char*,char*);
void MyStrCpy(char*,char*);
void MyStrCut(char*,char*);
int main()
{       char Str1[10];
        char Str2[10];
printf("Enter string1 \n");
scanf("%s",Str1);
printf("Enter string2 \n");
scanf("%s",Str2);
/*printf("%d\n",MyStrComp(Str1,Str2));
MyStrCpy(Str1,Str2);*/
MyStrCut(Str1,Str2);
	}

int MyStrComp(char* str1,char* str2)
{ int i=0;
int len1=strlen(str1);
int len2=strlen(str2);
for(i=0;str1[i]!='\0'&&str2[i]!='\0';i++)
{
	if(str1[i]>str2[i])
		return 1;
	else if(str1[i]<str2[i])
		return -1;
		   
}
if(len1==len2)
	return 0;
else if(len1>len2)
	return 1;
else if(len1<len2)
	return -1;
}
void MyStrCpy(char* str1,char* str2)
{ int i=0;
for(i=0;str2[i]!='\0';i++)
{
	str1[i]=str2[i];
	
		   
}
str1[i]=str2[i];
printf("%s\n",str1);
return; 
}

void MyStrCut(char* str1,char* str2)
{ int i=0;

int len1=strlen(str1);
for(i=0;str2[i]!='\0';i++)
{
	str1[len1+i]=str2[i];
	
		   
}
str1[len1+i]=str2[i];
printf("%s\n",str1);
return; 
}

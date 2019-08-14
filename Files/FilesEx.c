#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilesEx.h"

void lastNlines(int num,char* fname)
{	FILE* fp;
	char oneline[512];
	int* pos=malloc(sizeof(int)*num);
	int i=0;
        fp=fopen(fname,"r");
	if(fp!=NULL&&pos != NULL)
	{
		while(!feof(fp))
		{		pos[i%num]=ftell(fp);
				fgets(oneline,512,fp);
				i++;
			
			
		}
	
	fseek(fp,pos[i%num],0);
	while(!feof(fp))
	{
		fgets(oneline,512,fp);
		if(!feof(fp))
			printf("%s\n",oneline);
	}
	fclose(fp);
	free(pos);
	}
	
}

void counChr(char* fname)
{	FILE* fp;
	char chr;
	int countchr[58];
	int i=0;
	fp=fopen(fname,"r");
	for(i=0;i<58;i++)
	{
		countchr[i]=0;	
	}	
	if(fp!=NULL)
	{
		while(!feof(fp))
		{	
			chr=getc(fp);
			countchr[chr-'A']++;
				
		}
	for(i=0;i<58;i++)
	{	if(countchr[i]>0)
			printf("%c %d\n",i+'A',countchr[i]);
	}
	fclose(fp);
	}
}

void counWord(char* fname)
{	FILE* fp;
	FILE* fpout;
	CountWords_t** cwarr;
        CountWords_t** temp;
	CountWords_t* cw;
	int i=0,j=0,index=1;
	char word[50];
	int find=0;
	fp=fopen(fname,"r");
	cwarr = malloc(sizeof(CountWords_t*));
	fscanf(fp,"%s",word);
	cw=malloc(sizeof(CountWords_t));
	cwarr[0]=cw;
	strcpy(cwarr[0]->word,word);
	cwarr[0]->count=1;
	if(fp!=NULL)
	{
		while(!feof(fp))
		{	find=0; 
			fscanf(fp,"%s",word);
			for(i=0;i<index;i++)
			{	
				if(strcmp(word,cwarr[i]->word)==0&&!feof(fp))
				{	
					cwarr[i]->count++;
					find=1;
					break;

				}
			}
			if(find==0&&!feof(fp))
			{
				temp=realloc(cwarr,sizeof(CountWords_t)*(index+1));			
				if(temp!=NULL)
				{	cwarr=temp;	
					cw=malloc(sizeof(CountWords_t));
					cwarr[index]=cw;	
					strcpy(cwarr[index]->word,word);
					cwarr[index]->count=1;
					index++;
				}
			}
					
		}
		fclose(fp);
	}
	fpout=fopen("outtext.txt","w");
	for(j=0;j<index;j++)
	{
		fprintf(fpout,"%s %d\n",cwarr[j]->word,cwarr[j]->count);
	}
	fclose(fpout);
}















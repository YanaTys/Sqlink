
#include <openssl/md5.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "md5.h"
#include "init.h"
#include "fileOps.h"
#include "hashTable.h"
void printPoint(void * value);


int findRec(char * path,hashtable_t * hashTable){
    char **content;
    int index = 0;
    int i=0;
    unsigned char* md5Out;
    int status;
    void *voidPtr;

    content = getContent(path);

    while(content[index] != NULL)
    {        
        if(isFile(content[index]))
        {
            md5Out = md5Check(content[index]);
            status = insertHash(hashTable, md5Out, content[index]);
            findHash(hashTable, md5Out, &voidPtr);
            printf("\n%s \n",(char*)voidPtr);
            for(i=0;i<MD5_DIGEST_LENGTH;i++){
                 printf("%02x", md5Out[i]);
            }
            printf("\n");
    

                if(status == 3)
                {
                    findHash(hashTable, md5Out, &voidPtr);
                    printf("File %s already exist in %s\n", content[index], (char*)voidPtr);
                }
                free(md5Out);
                free(content[index]);
            
        }
        else if(isDir(content[index]))
        {
            findRec(content[index], hashTable);
            free(content[index]);
        }
        ++index;
    }
}

int findMyFiles(char * path){
 FILE * fp;
 hashtable_t * hash;
 int error;
 printElem printValue=printPoint;
 hash=createAll(path,hash,fp);

 /* if enum */
  error=findRec(path,hash);
  hashForEach(hash,printValue);  
  destroyAll(hash);

  return error;
}

int main(){
   char s[]="/home/sqrt23/Desktop/Test";
   findMyFiles(s);
   return 0;
}

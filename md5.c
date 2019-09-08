
#include <sys/mman.h>
#include <openssl/md5.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "md5.h"


unsigned char * md5Check(char * path)
{
   int fd;
   int n;
    MD5_CTX c;
    char buf[512];
    ssize_t bytes;
    unsigned char out[512];
    unsigned char* mdRes = (unsigned char*)malloc(MD5_DIGEST_LENGTH * sizeof(unsigned char));
    if (!out)
        return NULL;
    
    MD5_Init(&c);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return NULL;
    bytes=read(fd, buf, 512); 
    while(bytes > 0)
    {
        MD5_Update(&c, buf, bytes);
        bytes=read(fd, buf, 512);
    }

    MD5_Final(out, &c);
	
    for(n=0; n<MD5_DIGEST_LENGTH; n++)
         mdRes[n]=out[n];    


    close(fd);
    return(mdRes);  

    
}


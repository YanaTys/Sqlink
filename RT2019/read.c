#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "qMessage.h"

int main(int argc, char* argv [])
{
    int fd, ret;
    char* buffer=(char*)malloc(4096);
    fd=open(argv[1],O_RDONLY);
    if(fd==-1) {
        fprintf(stderr, "open error\n");
	return 1;
    }
    ret=ioctl(fd, MQ_RECV_MSG, buffer);
    if(ret==-1) {
        fprintf(stderr, "ioctl error\n");
	return 1;
    }
    printf("The message is %s\n", buffer);
    ret=close(fd);
    if(ret==-1) {
        fprintf(stderr, "close error\n");
	return 1;
    }
    return 0;
}

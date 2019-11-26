#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "qMessage.h"

int main(int argc, char** argv)
{
    int fd ,ret;
    struct mqReg reg;
    fd=open(argv[1],O_WRONLY);
    if(fd==-1) {
        fprintf(stderr, "open error\n");
	return 1;
    }
    reg.data=argv[2];
    reg.size=strlen(reg.data);
    ret=ioctl(fd,MQ_SEND_MSG,&reg);
    if(ret==-1) {
        fprintf(stderr, "ioctl error\n");
	return 1;
    }
    printf("return value from ioctl was %d\n", ret);
    ret=close(fd);
    if(ret==-1) {
        fprintf(stderr, "close error\n");
	return 1;
    }
    return 0;
}

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{   
   
    pid_t pid;
    pid= fork();
    if(pid>0)
    {
        wait(&pid);
    }
    else 
        execv("check",NULL);
        
    printf("end of program\n");
    return 0;
}
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sighandler(int, siginfo_t *, void *);

int main()
{
   int i=0;
   struct sigaction sa, osa;
   sa.sa_sigaction = sighandler;
   sa.sa_flags = SA_SIGINFO;
   sigaction(SIGINT, &sa, &osa);
   for (i=0;i<10;i++)
   {
       printf("%d\n",i);
       sleep(1);
   }
}
void sighandler(int signo, siginfo_t *si, void *vp)
{
   write(1, "Ayy...\n", 7);
}
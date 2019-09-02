#include<stdio.h> 
#include "progB.h"
void funcA ()
{
    printf("funcA worked\n");
}

int main ()
{   funcA();
    funcB();
    funcLib1();
    funcLib3();
    return 0;
}
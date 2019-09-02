#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(int argc, char **argv)
{
    void *handle;
    void (*funcLib2)();
    char *error;

   handle = dlopen("./libN.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();   

 

   *(void **) (&funcLib2) = dlsym(handle, "funcLib2");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
  
    funcLib2();
    dlclose(handle);
    exit(EXIT_SUCCESS);
    return 0;
    
}
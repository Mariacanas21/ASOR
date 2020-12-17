

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <errno.h>
#include <unistd.h>

int main(){
        char *path = "/";
        printf("Numero maximo de enlaces  %ld \n", pathconf(path,_PC_LINK_MAX));
        printf("Tamaño maximo de una ruta  %ld \n", pathconf(path,_PC_PATH_MAX));
        printf("Tamaño maximo de un nombre de fichero  %ld \n",pathconf(path,_PC_N$

   return 1;
}


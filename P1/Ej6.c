


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

        printf("Longitud maxima de los argumentos %ld \n", sysconf(_SC_ARG_MAX));
        printf("Numero maximo de hijos %ld \n", sysconf(_SC_CHILD_MAX));
        printf("Numero maximo de ficheros %ld \n",sysconf(_SC_OPEN_MAX));

   return 1;
}

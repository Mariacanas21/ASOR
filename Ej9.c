


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

        printf(" Uid real %i Uid efectivo %i\n",getuid(),geteuid()); 
        return 1;
}

/*
El fichero del programa tiene el bit setuid activado cuando
	el uid real y el efectivo son diferentes entre sí

*/

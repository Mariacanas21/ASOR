



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

int main(){
        struct timeval ini;
        struct timeval fin;

        gettimeofday(&ini,NULL);

        for(int i= 0; i < 1000000;i++){}

        gettimeofday(&fin,NULL);

        printf(" Tiempo en microsegundos  %ld \n", fin.tv_usec - ini.tv_usec);

        return 1;
}

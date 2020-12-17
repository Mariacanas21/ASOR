


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

int main(){
        time_t t = time(NULL);
        printf(" Tiempo %li \n", t);

        return 1;
}

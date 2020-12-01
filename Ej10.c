

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(){

        printf(" Uid real %i Uid efectivo %i\n",getuid(),geteuid()); 
        struct passwd* infor = getpwuid(getuid());      
        printf(" Nombre de usuario %s \n", infor->pw_name );
        printf(" Directorio home %s \n",infor->pw_dir );
        printf(" Descripción del usuario %s \n", infor->pw_gecos);
        return 1;
}


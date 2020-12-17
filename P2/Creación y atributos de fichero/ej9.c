

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main()
{
    struct stat buf;
    
    int fd = stat("/ej9.c", &buf);
    
    //Major y minor
    printf("Major %d \n", Major(buf.st_dev));
    printf("Minor %d \n", Minor(buf.st_dev));

    //Num de i-nodo
    printf("Num i-nodo %d \n", buf.st_ino);
    
    //Tipo de fichero
    printf(" Tipo de fichero ");
    mode_t mod = buf.st_mode();
   
    if(S_ISLINK(mod)){
        printf(" Simbolico \n");
    }
    else if(S_ISDIR(mod)){
        printf(" Directorio \n");
    }
    else if(S_ISREG(mod)){
        printf(" Fichero ordinario \n");
    }
    
    //Última hora de acceso
    /*
        ¿Qué diferencia hay entre st_mtime y st_ctime?
        st_ctime es la fecha del último cambio de estado
        st_mtime es la fecha de la última modificación
        
    */
    time_t tiempo = buf.st_atime;
    printf(" Último acceso ");
    struct tm *tmm = localtime(&tiempo);
    printf(" Hora %d Min %d Seg %d \n", tmm->tm_hour, tmm->tm_min, tmm->tm_sec);
    
    return 0;
}
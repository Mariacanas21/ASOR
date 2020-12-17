


#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <errno.h>

int main(){

   struct utsname informacion;
   if(uname(&informacion)!=-1){
        printf("Nombre del SO %s \n",informacion.sysname);
        printf("Nombre del host %s \n", informacion.nodename);
        printf("Release del SO %s \n", informacion.release);
        printf("Version del SO %s \n", informacion.version);
        printf("Hardware %s \n", informacion.machine);
   }
   else{
     printf("Error %d \n", strerror(errno));
     return -1;
  }
   return 1;
}

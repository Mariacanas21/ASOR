
#include <studio.h>
#include <stdio.h>
#include <errno.h>

int main(){
  char *s;
 if(setuid(0)==-1){
   printf("Error version num %d, cadena %s \n", errno, strerror(errno));
 }
  return 1;
}

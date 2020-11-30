


#include <studio.h>
#include <stdio.h>
#include <errno.h>

int main(){
 for(int i = 0; i < 255;i++){
   printf("Error version num %d, cadena %s \n", i, strerror(i));
 }
  return 1;
}

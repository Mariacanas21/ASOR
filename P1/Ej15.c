
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

int main(){
  time_t t = time(NULL);
 	struct tm *info = localtime(&t);
	char fech[256];

  //int a= info->tm_year;
	//a += 1900;
	strftime(fech,256,"%A,%H:%M",info);
 	printf("Fecha de hoy %s \n", fech);
  return 1;
}

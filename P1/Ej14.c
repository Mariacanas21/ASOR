

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

int main(){
  time_t t = time(NULL);
 	struct tm *info = localtime(&t);

  int a= info->tm_year;
	a += 1900;
 	printf("Año: %i\n",a);
  return 1;
}

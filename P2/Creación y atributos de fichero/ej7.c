

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	
	mode_t mask1;
	mask1 = umask(0027);
	int fd = open("ej7.txt",O_CREAT, 0645);
	mode_t mask2 = umask(mask1);
    	printf("ult %i \n", mask2);
	return 0;
}

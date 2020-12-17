
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	mode_t mask;
	mask = umask(0027);
	int fd = open("ej6.txt", O_CREAT, 0666);
	return 0;
}

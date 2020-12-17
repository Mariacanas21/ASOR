
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	const char *path = "/home/usuarioso/Escritorio/P2/ej5.txt";
	int fd = open(path,O_CREAT, 0645);
    printf("DESCR %d \n", fd);
	return 0;
}

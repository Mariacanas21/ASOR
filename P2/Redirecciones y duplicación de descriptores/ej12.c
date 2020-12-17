

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv){

	if(argc < 2){
		printf("Error en los argumentos de entrada \n");
		return -1;
	}

	int fd = open(argv[1], O_CREAT|O_RDWR,0777);
	if(fd != -1){
		int fdup = dup2(fd,1);
		printf("Redirigido a %s", argv[1]);
	}
	else{
		printf("Error de apertura de archivo \n");
		return -1;
	}


	return 0;
}
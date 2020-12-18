
#include <dirent.h>
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
		printf("Error de argumentos \n");
		return -1;
	}
	DIR *dir = opendir(argv[1]);

	if(dir != NULL){
		struct dirent *d = readdir(dir);
		struct stat s;
		int fdd = stat(d->d_name, &s);
		if(fdd != -1){
			if(S_ISREG(s.st_mode)){
				printf("Nombre %s \n", d->d_name);
			}
			else if(S_ISDIR(s.st_mode)){
				printf("Nombre %s '/' \n", d->d_name);
			}
			else if(S_ISLNK(s.st_mode)){
				int r = readlink(d->d_name, ,s.st_size);
				printf("Nombre %s '->' Fichero enlazado %d \n", d->d_name,r);
			}
		}
		else{
			printf("Error \n");
			return -1;
		}
	}
	else{
		printf("Error directorio \n");
		return -1;
	}
	close(dir);
	return 0;
}
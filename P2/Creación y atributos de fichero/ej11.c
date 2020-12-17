

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

int main(int argc, char *argv){

	if(argc < 2){
		printf("Error de argumentos ");
		return -1;
	}

	struct stat st;
	int sti = stat(argv[1],&st);

	if(sti == -1){
		printf("No existe el fichero ");
		return -1;
	}

	mode_t mode = st.st_mode;
	if(S_ISREG(mode)){
		char h[256];
		char s[256];
		strcpy(h,argv[1]);
		strcpy(s,argv[1]);
		strcat(h,".hard");
		strcat(s,".sym");
		int hlink = link(argv[1],h);
		int slink = link(argv[1],s);
		if(s == -1){
			printf("Error en la creación del enlace simbólico \n");
			return -1;
		}
		if(h == -1){
			printf("Error en la creación del enlace rígido \n");
			return -1;
		}
		printf("Ficheros creados correctamente \n");
	}

	return 0;
}

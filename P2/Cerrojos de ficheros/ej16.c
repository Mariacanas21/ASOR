


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

	int fd = open(argv[1],O_CREAT|O_RDWR,0777);

	if(fd != -1){
		struct flock lock;
		int block = fcntl(fd,F_GETLK,&lock);

		if(lock.l_type == F_UNLCK){
			char buff[256];
			time_t t = time(NULL);
			struct tm *tm = localtime(&t);
			srintf(buff," Hora %d , Min %d , Sec %d", tm->tm_hour, tm->tm_min, tm->tm_sec);
			write(fd,buff,size_of(buf));
			sleep(30);
			lock.l_type = F_WRLCK;
			lock.l_type = SEEK_SET;
			lock.l_start = 0;
			lock.l_len = 0;
			lock.l_pid = getpid();
		}
		else{
			printf("Estado Bloqueado \n ");
			return -1;
		}
	}
	else{
		printf("Error en la apertura del archivo \n");
		return -1;
	}
	close(fd);
	return 0;
}
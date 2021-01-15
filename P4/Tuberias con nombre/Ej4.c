
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>


int main(int argc, char *argv){
	int fd = open("./tuberia",O_WRONLY);
	ssize_t nbytes = strlen(argv[1]);
	write(fd,&argv[1]],nbytes);
	close(fd);

	return 0;
}




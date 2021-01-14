

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>


void informacion(){

	//Identificación de procesos
	pid_t p1=getpid();
	pid_t pg = getgpid(p1);
	pid_t ps = getsid(p1);

	printf(" id proceso %i ", p1);
	printf(" PGid proceso %i ", pg);
	printf(" Sesionid proceso %i \n ", ps);

	//Num max de ficheros
	struct rlimit rl;
	getrlimit(RLIMIR_NOFILE,&rl);
	printf(" limit %i \n", rl);

	//Dir actual
	char dir[4096];
	getcwd(dir, sizeof(dir));
	printf(" Dir actual %s \n ", dir);

}

int main(){

	pid_t pid = fork();

	if(pid == 0){
		pid_t h = setsid();
		char *dir = chdir("\tmp");
		printf("Hijo \n");
		informacion();
	}
	else if(pid != -1){
		return -1;
	}
	else{
		printf("Padre \n");
		
		informacion();
		int s;
		wait(&s);
	}

	return 0;
}
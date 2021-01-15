
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv){

	if(argc == 5){
		int p[2];
		int pi=pipe(p);
		pid_t pid = fork();

		if(pid == -1){
			return -1;
		}
		else if(pid == 0){
			dup2(p[0],0);
			close(p[0]);
			close(p[1]);
			execlp(argv[3],argv[3],argv[4],NULL);

		}
		else{
			dup2(p[1],1);
			close(p[0]);
			close(p[1]);
			execlp(argv[1],argv[1],argv[2],NULL);
		}
	}
	else{
		return -1;
	}
	return 0;
}


#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	sigset_t sg;

	sigemptyset(&sg);
	sigaddset(&sg, SIGINT);
	sigaddset(&sg, SIGTSTP);

	char *ss = getenv("SLEEP_SECS");
	
	int se = atoi(ss);

	sleep(se);

	sigset_t p;
	sigemptyset(&p);

	int n = sigismember(&p, SIGINT);
	
	if (n==1) printf("SIGINT recieved during sleep\n");
	else if(n==-1) return -1;

	n = sigismember(&p, SIGTSTP);
	if(n==1){ 
		printf("SIGTSTP \n");
		sigdelset(&sg, SIGINT);
		sigprocmask(SIG_UNBLOCK, &sg, NULL);
	}
	else if(n==-1){
		return -1;
	}


	return 0;
}
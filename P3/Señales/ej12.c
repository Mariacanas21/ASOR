


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int intc = 0,tstpc = 0;

void hler(int senal){
  if (senal == SIGINT) intc++;
  if (senal == SIGTSTP) tstpc++;
}

int main(){

  struct sigaction a;

  //Sigint
  sigaction(SIGINT, NULL, &a); 
  act.sa_handler = hler;
  sigaction(SIGINT, &a, NULL);
  //Sigtstp
  sigaction(SIGTSTP, NULL, &a);
  act.sa_handler = hler;
  sigaction(SIGTSTP, &a, NULL);

  sigset_t s;
  sigemptyset(&s);

	while (intc + tstpc < 10) sigsuspend(&s);

	printf("SIGINT contador %i\n", intc);
	printf("SIGTSTP contador %i\n", tstpc);


  return 0;
}
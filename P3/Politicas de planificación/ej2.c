

#include <stdlib.h>
#include <stdio.h>
#include <sched.h>


int main(int argc, char *argv){

	//Politica de planificación
	int p = atoi(argv[1]);
	int sc = sched_getscheduler(p);

	if(sc == 0){
		printf("SCHED_OTHER");
	}
	else if(sc == 1){
		printf("SCHED_FIFO");
	}
	else if(sc== 2){
		printf("SCHED_RR");
	}
	else{
		printf("ERROR");
	}

	//Prioridad
	struct sched_param pa;
sched_getparam(p,&pa);
	printf("Prioridad %i \n", p.sched_priority);

	//Valores max y min
	int ma = sched_get_priority_max(sc);
	printf(" MAX %i ", ma);
	ma = sched_get_priority_min(sc);
	printf(" MIN %i \n", ma);

	return 0;
}
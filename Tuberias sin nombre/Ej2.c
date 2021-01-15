

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int p_h[2],h_p[2];
	pipe(p_h);
	pipe(h_p);
	pid_t pid = fork();
	
	if(pid == -1){
		return -1;
	}
	else if (pid == 0){
		close(p_h[1]);
		close(h_p[0]);
		char mp[256];
		char padre[1]='1';
		for(int i = 0; i < 10;i++){
			ssize_t nbytes = read(p_h[0],mp,256);
			printf( "Hijo mp %s \n",mp);
			sleep(1);
			if(i == 9){padre[0]='q';}
			write(h_p[1], &padre,1);
		}
	}
	else{
		close(p_h[0]);
		close(h_p[1]);
		char mh[256];
		char hijo[1]='1';
		while(hijo[0] != 'q'){
			printf("Mensaje a leer ");
			ssize_t nbytes = read(0,mh,256);
			write(p_h[1], mh,nbytes);
			read(h_p[0],&hijo[0],1);
		}
	}
	printf("Mensajes completados \n");
	return 0;
}
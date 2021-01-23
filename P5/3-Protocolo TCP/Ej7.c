


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv){

	struct addrinfo hints;
	struct addrinfo *res;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

	int r = getaddrinfo(argv[1],argv[2],&hints,&res);
	int so = socket(res->ai_family,res->ai_socktype,,res->ai_protocol);
	int b = bind(so,res->ai_addr,res->ai_addrlen);
	listen(so,10);
	char host[NI_MAXHOST],ser[NI_MAXSERV], buff[256];
	while(1){
	int acc = accept(so, struct *sockaddr *addr, socklen_t *addrlen);
	getnameinfo(struct sockaddr &addr, addrlen,host,NI_MAXHOST,serv,NI_MAXSERV,NI_NUMERICHOST|NI_NUMERICSERV)
	}printf("Conexion desde %s %s\n", host, serv);

	ssize_t nbytes;

	while(nbytes >0){
		nbytes = recv(acc,buff,256*sizeof(char),0);
		if(buff[0] == 'q'){
			printf("Conexion terminada ");
			return -1;
		}
		if(nbytes > 0){
			ssize_t sen = send(acc,buff,(nbytes+1)*sizeof(char),0);
		}
	}
	return 0;
}
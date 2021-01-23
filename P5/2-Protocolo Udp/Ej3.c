
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

	int inf = getaddrinfo(argv[1],rgv[2],&hints,&res);
	int pro = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	sendto(pro,argv[3],strlen(argv[3]+1),0,res->ai_addr,res->ai_addrlen);
	char buff[256];
	ssize_t leido = recvfrom(pro,buff,256,0,res->ai_addr,res->ai_addrlen);
	if(leido == -1){
		printf("Error lectura \n");
		return -1;
	}
	else{
		printf(" leido %s\n", buff );
	}
	return 0;
	
}
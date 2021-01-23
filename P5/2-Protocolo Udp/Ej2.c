

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


int main(int argc, char *argv){

	struct addrinfo hints;
	struct addrinfo *res,*it;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

	int inf = getaddrinfo(argv[1],rgv[2],&hints,&res);
	int pro = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	int bi = bin(pro,res->ai_addr,res->ai_addrlen);

	char buff[2],host[NI_MAXHOST],ser[NI_MAXSERV];

	while(1){
	ssize_t nbytes = recvfrom(pro,buff,2,0,struct sockaddr *src_addr, socklent *addrlen);
	buff[1] = '\0';
	getnameinfo(struct sockaddr * &addr, &addrlen,host,NI_MAXHOST,serv,NI_MAXSERV,NI_NUMERICHOST|NI_NUMERICSERV);
	printf("%i bytes de %s : %s \n",nbytes,host,serv);
	time_t ti = time(NULL);
	struct tm *tm = localtime(&ti);
	char d[50];
	if(buf[0] == 't'){
		ssize_t nbb = strftime(d,size_t m, "%I:%M: ", tm);
		sendto(pro,d,nbb,0, struct sockaddr * &c_addr, c_addrlen);
	}
	else if(buf[0] == 'd'){
		ssize_t nb = strftime(d,size_t m, "%Y-%M-",tm);
		sendto(pro,d,nbb,0, struct sockaddr * &c_addr, c_addrlen);
	}
	else if(buf[0] == 'q'){
		printf("Saliendo \n");
		return 0;
	}
	else{
		return -1;
	}
	}
	return 0;
	
}

execvp


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){

  if (argc < 2) {
    printf("ERROR \n");
    return -1;
  }

  char command[256];
  strcpy(command, argv[1]);
  for(int i= 2; i < argc; i++) {
	strcat(command, " ");
	strcat(command,argv[i]);
   }
	
	system(command);


  return 0;
}

system


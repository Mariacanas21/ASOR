


int main(int argc, char *argv){

  pid_t pid = fork();

  switch (pid) {
    if(pid = -1){
    	exit(-1);
    }
    else if (pid == 0){
      pid_t mi_sid = setsid(); 
      printf("Hijo %i \n",getpid());
      int fd = open("/tmp/daemon.out",O_CREAT | O_RDWR, 00777);
      int fderr = open("/tmp/daemon.err", O_CREAT | O_RDWR, 00777);
      int null = open("/dev/null", O_CREAT | O_RDWR, 00777);
      int fd2 = dup2(fd,2);
      int fd3 = dup2(fderr, 1);
      int fd4 = dup2(null, 0);

      execvp(argv[1], argv + 1);
     }
    else{
        printf("Padre \n",getpid());
    }
  }

  return 0;
}
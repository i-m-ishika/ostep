#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h> // for file descriptors
#include<sys/wait.h>

int main(int argc, char* argv[]){
  int rc = fork();
  
  if (rc < 0) {
    fprintf(stderr, "Fork failed.\n");
  } else if (rc == 0) {
    // redirect stdout to a file.
    // p4.output
    close(STDOUT_FILENO);
    // file permissions:
    // S_IRUSR: Read permission for owner
    // S_IWUSR: Write permission for owner
    // S_IRGRP: Read permission for grp
    // S_IROTH: Read permission for others
    mode_t permissions = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;
    open("./p4.output", O_CREAT|O_WRONLY, permissions);
    char* my_argv[3];
    my_argv[0] = strdup("wc");
    my_argv[1] = strdup("p4.c");
    my_argv[2] = NULL;
    execvp(my_argv[0], my_argv);
  } else {
    int rc_wait = wait(NULL);
  }

  return 0;
}


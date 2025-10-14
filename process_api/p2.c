#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
  printf("pid: (%d)\n", (int)getpid());

  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "Fork failed.\n");
  } else if (rc == 0) {
    // Block executed by child (new process).
    printf("child process: (%d)\n", (int)getpid());
  } else {
    // Block executed by parent (main).
    int rc_wait = wait(NULL);
    printf("parent of %d (rc_wait: %d): (%d)\n",
        rc, rc_wait, (int)getpid());
  }
  return 0;
}

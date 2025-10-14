#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  // Child and parent are executed non-deterministically.
  printf("pid: (%d)\n", (int)getpid());

  int rc = fork();
  if (rc<0) {
    // fork failed
    fprintf(stderr, "Fork failed.\n");
    exit(1);
  } else if (rc == 0) {
    // Block executed by child (new process). fork() returns 0 to child process.
    printf("child process: (%d)\n", (int)getpid());
  } else {
    // Block executed by parent (main). fork() returns child pid to the parent process.
    printf("parent of %d: (%d)\n", rc, (int)getpid());
  }
  return 0;
}

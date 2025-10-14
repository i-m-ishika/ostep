#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
  /*
   * The exec system call is useful when we want to run a program that is different from the calling program.
   * Calling fork() is only useful if we want to keep running copies of the same program.
   * What exec does: given the name of the executable (wc here) and some args, it loads code and static data from that executable and overwrites the current code segment and static data with it. The heap and stack and other parts of the memory space of the program are re-initialized. The OS simply runs this program (along with any argv passed).
   * Thus, exec doesn't create a new process, it transforms the currently running program (p3) into a different running program (wc).
   *
   * A successfull call to exec never returns.
   * */
  printf("pid: (%d)\n", (int)getpid());

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "Fork failed.");
  } else if (rc == 0) {
    printf("child pid: (%d)\n", (int)getpid());
    // Load new program to be executed in child.
    char *my_argv[3];
    my_argv[0] = strdup("wc");    // program
    my_argv[1] = strdup("p3.c");  // arg: input file
    my_argv[2] = NULL;            // end of array
    execvp(my_argv[0], my_argv);  // runs word count program.

    printf("This is unreachable code.\n");
  } else {
    int rc_wait = wait(NULL);
    printf("parent of %d (rc_wait:%d): (%d)\n",
        rc, rc_wait, (int)getpid());
  }
  return 0;
}

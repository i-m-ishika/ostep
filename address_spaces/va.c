#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  // Code Segment
  printf("location of code  : %p\n", main);
  // allocate 100mb of data; malloc returns pointer to the newly allocated block if successful.
  printf("location of heap  : %p\n", malloc(100e6));
  int x = 2;
  // Stack Segment (local variables are stored on stack).
  printf("location of stack : %p\n", &x);
  return 0;
}

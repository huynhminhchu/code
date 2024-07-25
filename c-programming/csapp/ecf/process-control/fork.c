#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  pid_t pid;
  int x = 1;

  pid = fork();
  check(pid >= 0, "Can't fork.");
  if (pid == 0) {
    printf("Child: x=%d\n", ++x);
    exit(EXIT_SUCCESS);
  }

  /* Parent */
  printf("Parent: x=%d\n", --x);
  exit(EXIT_SUCCESS);
error:
  return -1;
}

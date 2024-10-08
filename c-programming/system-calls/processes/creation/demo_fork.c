#include <dbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int idata = 111; // ALlocated in data segment
//

int main(int argc, char *argv[]) {
  int istack = 222; // Allocated in stack segment

  pid_t childPid;
  switch (childPid = fork()) {
  case -1:
    sentinel("fork");
  case 0:
    idata *= 3;
    istack *= 3;
    break;
  default:
    sleep(3); // Give child a chance to execute
    break;
  }

  printf("PID=%ld %s idata=%d istack=%d\n", (long)getpid(),
         (childPid == 0) ? "(child) " : "(parent)", idata, istack);
  exit(EXIT_SUCCESS);
error:
  return -1;
}

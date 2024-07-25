#include "dbg.h"
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#define N 5
int main(int argc, char *argv[]) {
  int status, i;
  pid_t pid;

  for (i = 0; i < N; i++)
    if ((pid = fork()) == 0) /* Child */
      exit(100 + i);

  while ((pid = waitpid(-1, &status, 0)) > 0) {
    /* If the child exited normally
     */
    if (WIFEXITED(status))
      log_info("Child %d terminated normally with exit status = %d", pid,
               WEXITSTATUS(status));
    else
      sentinel("Child %d terminated abnormally", pid);
  }

  // The only normal termination is if there are no more children
  check(errno == ECHILD, "waitpid error");
  exit(0);
error:
  return -1;
}

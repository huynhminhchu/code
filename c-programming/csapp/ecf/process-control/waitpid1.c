#include <dbg.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define N 2

int main() {
  int status, i;
  pid_t pid;

  for (i = 0; i < N; i++) {
    pid = fork();
    check(pid >= 0, "fork failed.");
    if (pid == 0) // child
      exit(100 + i);
  }

  // Parent reaps N children in no particular oder
  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status))
      log_info("child %d terminated normally with exit status =%d", pid,
               WEXITSTATUS(status));
    else
      log_info("child %d terminated abnormally.", pid);
  }

  if (errno != ECHILD)
    sentinel("waitpid error");
error:
  return -1;
}

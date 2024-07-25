#include "dbg.h"
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int s, sig, pid;
  check(argc == 3 && strcmp(argv[1], "--help") != 0, "%s sig-num pid\n",
        argv[0]);

  // Simplify arg check
  // Assume that sig is correct.
  pid = atoi(argv[1]);
  sig = atoi(argv[2]);

  s = kill((pid_t)pid, sig);
  if (s == -1) {
    // Error
    if (errno == EPERM)
      log_info(
          "Process exists, but we don't have permission to send it a signal");
    else if (errno == ESRCH)
      log_info("Process doesn't exist");
    else
      sentinel("kill");
  } else {
    // Kill successfully
    log_info("Process exists and we can send it a signal\n");
  }

  exit(EXIT_SUCCESS);
error:
  return -1;
}

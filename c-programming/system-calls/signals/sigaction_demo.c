#include "dbg.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t unprocessedSig = 0;
void sighandler(int sig) {
  if (sig == SIGINT)
    unprocessedSig = 1;
}
int main() {
  printf("This is pid %d\n", getpid());

  struct sigaction act;
  act.sa_handler = &sighandler;

  // All signal will be blocked while our signal handler function is running.
  // The original signal mask will be restored when our signal handler exits
  // normally;
  sigfillset(&act.sa_mask);

  /*
   If the signal handler gets run in the middle of system call (like open(),
   read(),...) and the signal handler returns normally, restart system calls
   interrupted by the signal handler
    */
  act.sa_flags = SA_RESTART;
  if (sigaction(SIGINT, &act, NULL) == -1)
    sentinel("sigaction");

  printf("IMPORTANT: kill this process by running 'killall -9 sigaction_demo' "
         "in another terminal\n");
  while (1) {
    if (unprocessedSig) {
      unprocessedSig = 0;
      printf("SIGINT signal occurred.\n");
    }
  }
  return 0;
error:
  return -1;
}

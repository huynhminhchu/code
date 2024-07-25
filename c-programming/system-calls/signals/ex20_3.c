#include "dbg.h"
#include "signal_functions.h"
#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int sigCnt[NSIG]; // Counts deliveries of each signal
static volatile sig_atomic_t gotSigint =
    0; // Set nonzero if SIGINT is delivered

static volatile sig_atomic_t count = 0;

static void handler(int sig) {
  if (sig == SIGINT)
    gotSigint = 1;
  else {
    log_info("caught signal %d.", sig);
    log_info("Sleep for 5s");
    sleep(5);
    log_info("Done in signal handler");
  }
}
int main(int argc, char *argv[]) {

  sigset_t blockingMask, pendingMask, emptyMask;
  log_info("%s: PID is %ld\n", argv[0], (long)getpid());
  /*
    Setting  all signal dispositions to count deliveries of each signal
   */

  struct sigaction act;
  act.sa_handler = &handler;
  // sigfillset(&act.sa_mask); // block all signal while signal handler function
  // is running
  // SA_NODEFER: when signal x is caught, dont add it automatically to the
  // process signal mask SA_RESETHAND: when signal x is caught, set x's
  // disposition to default (SIG_DFL) (after sa_handler is executed)
  act.sa_flags = SA_NODEFER | SA_RESETHAND;
  check(sigaction(SIGUSR1, &act, NULL) != -1, "sigaction");

  log_info(
      "IMPORTANT: send a signal to test by running './sig_sender $PID 2 10'");
  while (!gotSigint) {
    continue;
  }
error:
  return -1;
}

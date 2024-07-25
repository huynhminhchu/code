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
//
static void handler(int sig) {
  if (sig == SIGINT)
    gotSigint = 1;
  else
    sigCnt[sig]++;
}
int main(int argc, char *argv[]) {

  int time_sleep;
  sigset_t blockingMask, pendingMask, emptyMask;
  log_info("%s: PID is %ld\n", argv[0], (long)getpid());
  /*
    Setting  all signal dispositions to count deliveries of each signal
   */
  for (int i = 1; i < NSIG; i++)
    (void)signal(i, handler);

  check(argc > 1, " number of args must be > 1");

  // Simplify arg passing
  time_sleep = atoi(argv[1]);

  /*
   Blocking all signal
  */
  sigfillset(&blockingMask);
  check(sigprocmask(SIG_SETMASK, &blockingMask, NULL) == 0, "sigprocmask");

  // Sleep few seconds and send a signal from another terminal in this time
  log_info("%s: sleep for %d seconds", argv[0], time_sleep);
  sleep(time_sleep);
  /*
   Check the pending signals in this time
   */
  // check(sigpending(&pendingMask) == 0, "sigpending");
  printPendingSigs(stdout, "Current pending signals of this process\n");

  /*
   Change the disposition of pending signals to SIG_IGN, the program will never
   catch the signal
   */
  for (int sigint = 1; sigint < NSIG; sigint++) {

    // Allow signal 12 to be caught
    if (sigint == 12)
      continue;
    if (sigismember(&pendingMask, sigint)) {
      (void)signal(sigint, SIG_IGN);
    }
  }

  /*
   Unblock all signals
   */
  sigemptyset(&emptyMask);
  check(sigprocmask(SIG_SETMASK, &emptyMask, NULL) == 0,
        "sigprocmask empty mask");

  // Loop until SIGINT caught
  for (int n = 1; n < NSIG; n++)
    if (sigCnt[n] != 0)
      log_info("%s: signal %d caught %d times", argv[0], n, sigCnt[n]);
  exit(EXIT_SUCCESS);
error:
  return -1;
}

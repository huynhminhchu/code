#include "dbg.h"
#include "signal_functions.h"
#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
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
  int n, numSecs;
  sigset_t pendingMask, blockingMask, emptyMask;
  log_info("%s: PID is %ld\n", argv[0], (long)getpid());

  /*
   Setting signal disposition for all signals
   * */

  struct sigaction act;
  act.sa_handler = &handler;
  sigfillset(&act.sa_mask); // all signal will be blocked when our signal
                            // handler function is running
  act.sa_flags = SA_RESTART;

  for (n = 1; n < NSIG; n++)
    (void)sigaction(n, &act, NULL);

  if (argc > 1) {
    /*
     Receiver will block signals for n seconds
     */
    numSecs = atoi(argv[1]);

    sigfillset(&blockingMask);
    if (sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1)
      sentinel("sigprocmask");

    log_info("%s: sleep for %d seconds\n", argv[0], numSecs);
    sleep(numSecs);

    if (sigpending(&pendingMask) == -1)
      sentinel("sigpending");

    log_info("%s: pending signals are: \n", argv[0]);
    printSigset(stdout, "\t\t", &pendingMask);
    sigemptyset(&emptyMask); // Unblock all signals
    if (sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1)
      sentinel("sigprocmask");
  }

  // Loop until SIGINT caught
  while (!gotSigint)
    continue;

  for (n = 1; n < NSIG; n++)
    if (sigCnt[n] != 0)
      log_info("%s: signal %d caught %d times", argv[0], n, sigCnt[n]);
  exit(EXIT_SUCCESS);
error:
  return -1;
}

/*
./sig_receiver 10 &
*/

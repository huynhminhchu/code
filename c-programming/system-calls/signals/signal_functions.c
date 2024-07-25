
#define _GNU_SOURCE

#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

// This is just for demo, do not use not async-signal-safe functions like
// fprintf()
//
//

void printSigset(FILE *of, const char *prefix, const sigset_t *sigset) {
  int sig, cnt;
  cnt = 0;

  for (sig = 1; sig < NSIG; sig++) {
    if (sigismember(sigset, sig) == 1) {
      cnt++;
      fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
    }
  }
  if (cnt == 0)
    fprintf(of, "%s<empty signal set>\n", prefix);
}

int printSigMask(FILE *of, const char *msg) {
  sigset_t currMask; // current sig mask
  if (msg != NULL)
    fprintf(of, "%s", msg);

  if (sigprocmask(SIG_BLOCK, NULL, &currMask) == -1)
    return -1;

  printSigset(of, "\t\t", &currMask);

  return 0;
}

int printPendingSigs(FILE *of, const char *msg) {
  sigset_t pendingSigs;

  if (msg != NULL)
    fprintf(of, "%s\n", msg);

  if (sigpending(&pendingSigs) == -1)
    return -1;
  printSigset(of, "\t\t", &pendingSigs);

  return 0;
}

// int main(int argc, char *argv[]) {
//   sigset_t newSigset, currSigset;
//   int s;
//   s = sigemptyset(&newSigset);
//   if (s == -1)
//     return -1;
//
//   printf("Initial signal mask\n");
//   printSigset(stdout, "\t", &newSigset);
//
//   printf("Adding SIGINT to newSigset");
//   sigaddset(&newSigset, SIGINT);
//
//   printf("Block SIGINT using sicprocmask\n");
//   int b;
//   b = sigprocmask(SIG_BLOCK, &newSigset, &currSigset);
//   if (b == -1)
//     return -1;
//
//   printf("Signal mask after adding block to sig mask:\n");
//   printSigMask(stdout, "\t");
//
//   printf("Now use rais() to send a SIGINT signal to the process itself\n");
//   if (raise(SIGINT) != 0)
//     return -1;
//   printf("Check if SIGINT is in the pending set\n");
//   printPendingSigs(stdout, "\t");
//   return 0;
// }

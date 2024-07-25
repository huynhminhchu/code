#include "dbg.h"
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int numSigs, sig, j;

  pid_t pid;
  check(argc >= 4 && strcmp(argv[1], "--help") != 0,
        "%s pid num-sigs sig-num [sig-num-2]\n", argv[0]);

  pid = (long)atoi(argv[1]);
  numSigs = atoi(argv[2]);
  sig = atoi(argv[3]);

  log_info("%s: sending signal %d to process %ld %d times.", argv[0], sig,
           (long)pid, numSigs);

  for (j = 0; j < numSigs; j++) {
    if (kill(pid, sig) == -1)
      sentinel("kill");
  }
  /* If a fourth command-line argument was specified, send that signal*/
  if (argc > 4)
    if (kill(pid, atoi(argv[4])) == -1)
      sentinel("kill");

  log_info("%s: exiting\n", argv[0]);
  exit(EXIT_SUCCESS);

error:
  return -1;
}

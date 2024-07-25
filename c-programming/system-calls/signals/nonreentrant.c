#define _XOPEN_SOURCE
#include "dbg.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char *str2;      // set from argv[2]
static int handled = 0; // count number of calls to handler

static void handler(int sig) {
  crypt(str2, "xx");
  handled++;
}

int main(int argc, char *argv[]) {
  char *cr1;
  int callNum, mismatch;
  struct sigaction sa;

  check(argc == 3, "%s str1 str2\n", argv[0]);

  str2 = argv[2];
  // copy statically allocated string to another buffer
  cr1 = strdup(crypt(str2, "xx"));

  if (cr1 == NULL)
    sentinel("strdup");

  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sa.sa_handler = handler;

  if (sigaction(SIGINT, &sa, NULL) == -1)
    sentinel("sigaction");

  for (callNum = 1, mismatch = 0;; callNum++) {
    if (strcmp(crypt(argv[1], "xx"), cr1) != 0) {
      mismatch++;
      log_info("Mismatch on call %d (mismatch=%d handled=%d)", callNum,
               mismatch, handled);
    }
  }

error:
  return -1;
}

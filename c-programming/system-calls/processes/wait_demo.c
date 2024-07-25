#include "dbg.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 1000

char *currTime(const char *format);
int main(int argc, char *argv[]) {
  int numDead = 0; // Number of children so far waited for
  pid_t childPid;  // PID of waited for child

  int j;
  check(argc >= 2 && (strcmp(argv[1], "--help") != 0), "%s sleep-time...",
        argv[0]);

  /* Disable buffering of stdout */
  setbuf(stdout, NULL);

  // Create 1 child for each argument
  for (j = 1; j < argc; j++) {
    switch (fork()) {
    case -1:
      sentinel("fork");
    case 0:
      /* Child sleeps for a while then exits
       */
      log_info("[%s] child %d started with PID %ld, sleeping %s "
               " seconds\n",
               currTime("%T"), j, (long)getpid(), argv[j]);
      sleep((unsigned int)atoi(argv[j]));
      exit(EXIT_SUCCESS);
    default:
      break;
    }
  }
  for (;;) {
    childPid = wait(NULL);
    if (childPid == -1) {
      // Error
      if (errno == ECHILD) {
        log_info("No more children - bye!");
        exit(EXIT_SUCCESS);
      } else {
        sentinel("wait");
      }
    }

    numDead++;
    log_info("[%s] wait() returned child PID %ld (numDead=%d)\n",
             currTime("%T"), (long)childPid, numDead);
  }

  return 0;

error:
  return -1;
}

char *currTime(const char *format) {
  static char buf[BUF_SIZE]; /* Nonreentrant */
  time_t t;
  size_t s;
  struct tm *tm;

  t = time(NULL);
  tm = localtime(&t);
  if (tm == NULL)
    return NULL;

  s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

  return (s == 0) ? NULL : buf;
}

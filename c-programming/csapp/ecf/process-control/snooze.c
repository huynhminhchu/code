#include <dbg.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static volatile sig_atomic_t gotSigint = 0;

static void handler(int sig)
{
    if (sig == SIGINT)
        return;
}

unsigned int snooze(unsigned int secs) {
  int n = sleep(secs);
  printf("\nSlept for %d of %d secs.\n", secs - n, secs);
  return n;
}

int main(int argc, char *argv[]) { 
    
    if (signal(SIGINT, handler) == SIG_ERR)
        printf("Signal error\n");
    int secs = atoi(argv[1]);
    snooze(secs);
}


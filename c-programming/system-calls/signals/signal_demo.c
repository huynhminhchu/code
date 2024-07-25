#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigint_handler(int sig) { printf("Caught SIGINT\n"); }

int main() {
  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    printf("Signal error\n");

  pause();
}

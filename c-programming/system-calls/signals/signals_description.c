#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Signal description: %s\n", strsignal(2));
  return 0;
}

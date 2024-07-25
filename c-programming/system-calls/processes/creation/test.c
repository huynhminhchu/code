#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t childPid;
  switch (childPid = fork()) {
  case -1:
    printf("Error.\n");
  case 0:
    printf("I am a child.\n");
    exit(0);
  default:
    printf("I am parent.\n");
  }
}

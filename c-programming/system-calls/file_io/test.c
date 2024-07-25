#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int inputFd;
  inputFd = open(argv[1], O_WRONLY);
  printf("Input fd value: %d\n", inputFd);

  int copyFd = dup(inputFd);
  printf("Copy fd value: %d\n", copyFd);
  int sz = write(copyFd, "hello geeks2\n", strlen("hello geeks\n"));
}

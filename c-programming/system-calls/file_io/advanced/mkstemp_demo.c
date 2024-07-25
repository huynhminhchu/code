#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd;
  char template[] = "/tmp/somestringXXXXXX";

  fd = mkstemp(template);
  if (fd == -1)
    fprintf(stderr, "mkstemp error\n");

  printf("Generated filename was: %s\n", template);
  unlink(template);

  // use file i/o system calls

  // close
  if (close(fd) == -1)
    fprintf(stderr, "close error\n");
}

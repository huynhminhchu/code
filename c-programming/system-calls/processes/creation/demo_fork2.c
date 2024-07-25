#include <dbg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd, flags;
  char template[] = "/tmp/testXXXXXX";

  // Disable buffering of stdout
  setbuf(stdout, NULL);

  fd = mkstemp(template);
  if (fd == -1)
    sentinel("mkstemp");

  log_info("File offset before fork(): %lld\n",
           (long long)lseek(fd, 0, SEEK_CUR));

error:
  return -1;
}

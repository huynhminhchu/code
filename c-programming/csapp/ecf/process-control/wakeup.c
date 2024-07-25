#include <dbg.h>
#include <unistd.h>

unsigned int wakeup(unsigned int secs) {
  int n = sleep(secs);
  log_info("Woke up at %d secs.", secs - n);
  return n;
}

int main(int argc, char *argv[]) { 
  printf("Hello World\n");
  wakeup(5);
}

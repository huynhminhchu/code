#include <stdio.h>
#include <time.h>

int main() {

  time_t now;
  time(&now);

  printf("The computer thinks it's %ld\n", now);
  // The number of seconds of tick-tocking since 1970
  printf("%s", ctime(&now));

  return 0;
}

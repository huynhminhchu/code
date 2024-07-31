#include <stdio.h>
#include <time.h>

int main() {

  time_t now;
  time(&now);

  printf("The computer thinks it's %ld\n", now);
  // The number of seconds of tick-tocking since 1970
  printf("%s", ctime(&now));

  struct tm *clock;
  clock = localtime(&now);
  puts("Time details:");
  printf(" Day of the year: %d\n", clock->tm_yday);
  printf(" Day of the week: %d\n", clock->tm_wday);
  printf("            Year: %d\n", clock->tm_year);

  return 0;
}

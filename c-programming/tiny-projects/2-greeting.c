#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

  time_t now;
  time(&now);
  struct tm *clock;
  clock = localtime(&now);
  int hour = clock->tm_hour;
  char *name = "Chu";

  printf("Good ");
  if (hour + 7 < 12) {
    printf("morning, ");
  } else if (hour + 7 >= 12 && hour + 7 < 17) {
    printf("afternoon, ");
  } else {
    printf("evening, ");
  }
  if (argv[1] != NULL)
    name = argv[1];
  printf("%s!!!\n", name);
  printf("Today is %d, %d %d, %d\n", clock->tm_wday, clock->tm_mday,
         clock->tm_mday, clock->tm_year + 1900);
  printf("It's %s", ctime(&now));
  return 0;
}

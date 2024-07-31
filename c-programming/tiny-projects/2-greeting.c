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
  printf("%s!!!", name);

  char time_string[64];
  strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
  printf("!\n%s", time_string);

  return 0;
}

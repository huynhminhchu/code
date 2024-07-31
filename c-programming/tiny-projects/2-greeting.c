#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main(int argc, char *argv[]) {

  srand((unsigned)time(NULL));
  int saying;

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

  const char filename[] = "pithy.txt";
  FILE *fp;
  char buffer[BSIZE];
  char *r;
  char *entry; // allocated based on the size of the line read from the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open the file %s\n", filename);
    exit(1);
  }

  int items, x;
  char **list_base;

  items = 0;
  list_base = (char **)malloc(sizeof(char *) * 100);
  if (list_base == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(1);
  }

  while (!feof(fp)) {
    r = fgets(buffer, BSIZE, fp);
    if (r == NULL)
      break;

    entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
    if (entry == NULL) {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(1);
    }
    strcpy(entry, buffer);
    if (items % 100 == 0) {
      char **new_list_base = realloc(list_base, sizeof(char *) * (items + 100));
      if (new_list_base != NULL) {
        list_base = new_list_base;
      }
    }
    *(list_base + items) = entry;
    /* printf("d: %s", items, entry); */
    items++;
  }
  saying = rand() % (items);
  printf("Items: %d\n", items);
  printf("Saying: %d\n", saying);
  printf("%s", *(list_base + saying));
  fclose(fp);

  for (int i = 0; i < 5; i++)
    printf("%d\n", rand() % (2 - 1));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main() {
  const char filename[] = "pithy.txt";
  FILE *fp;
  char buffer[BSIZE];
  char *r;
  char *entry; // allocated based on the size of the line read from the file
  // copy bfrom buffer to entry

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
    *(list_base + items) = entry;
    /* printf("d: %s", items, entry); */
    items++;
  }
  for (int i = 0; i < items; i++)
    printf("%s", *(list_base + i));
  fclose(fp);
}

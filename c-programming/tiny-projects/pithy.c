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

  while (!feof(fp)) {
    r = fgets(buffer, BSIZE, fp);
    if (r == NULL)
      break;
    printf("%s", buffer);
    printf("Size of buffer: %ld\n", strlen(buffer));
  }
  fclose(fp);
}

#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256

int main() {
  const char filename[] = "pithy.next";
  FILE *fp;
  char buffer[BSIZE];
  char *r;

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
  }
  fclose(fp);
}

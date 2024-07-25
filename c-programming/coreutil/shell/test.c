#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char **array) {
  array[0] = "hello ";
  array[1] = "world\n";
}

void eval() {
  char *arguments[100];
  printf("Arguments[0]: \"%s\"\n", arguments[0]);
  change(arguments);
}

int main(int argc, char *argv[]) {
  char str[] = " Geeks  for   Geeks\n\n\n";

  char *s = getenv("PATH");
  printf("PATH env: \"%s\"\n", s);

  return 0;
}

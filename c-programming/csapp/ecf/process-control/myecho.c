#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[]) {
  printf("Command-ine arguments\n");
  for (int i = 0; i < argc; i++) {
    printf("\t\t argv[%d]: %s\n", i, argv[i]);
  }
  printf("Environment variables:\n");
  char **p = environ;
  int i = 0;
  while (*p != NULL)
    printf("\t\t envp[%d]: %s\n", i++, *p++);

  return 0;
}

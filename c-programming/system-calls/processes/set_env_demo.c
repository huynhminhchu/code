#include <stdio.h>
#include <stdlib.h>

int setenv_demo(const char *name, const char *value, int overwrite) {
  char *env = malloc(200);
  sprintf(env, "%s=%s", name, value);
  if (overwrite == 0) {
    char *p = getenv(name);
    if (p == NULL) {
      printf("Env check: %s\n", env);
      if (putenv(env) == 0)
        return 0;
      return -1;

    } else {
      printf("Env already exists\n");
      return -1;
    }
  }
}

int main(int argc, char *argv[]) {
  setenv_demo("TEST", "HW", 0);
  return 0;
}

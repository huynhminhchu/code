#include <stdio.h>
#include <stdlib.h>

int fun(int a, int *bp) { return a + *bp; }
int call_fun(int x, int y) { return fun(x, &y); }

int main(int argc, char *argv[]) {

  int x = 10;
  int y = 20;
  call_fun(x, y);
  return 0;
}

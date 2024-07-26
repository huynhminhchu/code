#include <stdio.h>

typedef char src_t;
typedef int dest_t;
void do_something(src_t v, dest_t *p) {

  *p = (dest_t)v;
  printf("Hello from function.\n");
}
int main(int argc, char *argv[]) {

  src_t v = 'A';
  dest_t *p;

  *p = 10;
  do_something(v, p);
  printf("Hello from main.\n");
}

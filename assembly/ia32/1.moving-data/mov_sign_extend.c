#include <stdio.h>

typedef char src_t;
typedef int dest_t;
void do_something() {
  src_t v;
  dest_t *p;

  v = 'A';
  *p = 10;
  printf("Hello from function.\n");
}
int main(int argc, char *argv[]) { printf("Hello from main.\n"); }

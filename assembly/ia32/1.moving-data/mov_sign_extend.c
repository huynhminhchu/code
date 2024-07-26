#include <stdio.h>

typedef char src_t;
typedef int dest_t;
int main(int argc, char *argv[]) {
  src_t v;
  dest_t *p;

  v = 'A';
  *p = 10;
}

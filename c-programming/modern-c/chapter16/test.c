#include <stdio.h>


typedef struct {
    enum {INT_KIND, DOUBLE_KIND} kind;
    union {
        int i;
        double d;
    } u;
} Number;

void print_number(Number n)
{
    if (n.kind == INT_KIND)
        printf("%d\n", n.u.i);
    else
        printf("%g\n", n.u.d);
}
int main(void)
{
    Number n;
    n.kind = INT_KIND;
    n.u.i = 82;
    print_number(n);
    n.kind = DOUBLE_KIND;
    n.u.d = 12.3;
    print_number(n);
}
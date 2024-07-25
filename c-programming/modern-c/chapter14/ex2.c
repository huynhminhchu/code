#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))


int main(void)
{
    int a[] = {1,2,3,4,5};
    printf("Size of a: %zu\n", NELEMS(a));
}
#include "stack.h"
#include <stdio.h>

int main(void)
{
    push(100);
    push(55);
    int n = pop();
    printf("Value of n = %d\n", n);
}
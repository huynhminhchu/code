#include <stdio.h>

#define CUBE(x) ((x)*(x)*(x))
#define DIVIDE_FOUR(x) ((x)%4)
#define LESS_THAN_HUNDRED(x,y) ((x)*(y)<100 ? 1 : 0)


int main(void)
{
    int n = 10;
    printf("Cube 10: %d\n", CUBE(10));
    int b = 23;
    printf("Remainder when divide by 4: %d\n", DIVIDE_FOUR(b));

    printf("Less than 100: %d\n", LESS_THAN_HUNDRED(10,50));
}
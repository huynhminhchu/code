#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DISP(x,y) printf(#x " (%g) = %g\n", x,y)

int main(void)
{
    DISP(sqrt, 3.0);

}
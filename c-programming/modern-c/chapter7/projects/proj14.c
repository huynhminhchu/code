#include <stdio.h>
#include <stdlib.h>

int main(){

    double x, x_div_y, average;
    double y = 1.0f;
    printf("Enter a positive number: ");
    scanf("%lf", &x);

    average = (x/y + y)/2.0;

    while (fabs((x/y + y)/2.0 - y) >= (0.00001*y)){
        y = (x/y + y)/2.0;
    }

    printf("Square root: %.5f\n", y);
}
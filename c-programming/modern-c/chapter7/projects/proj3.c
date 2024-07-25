#include <stdio.h>

int main(void){
    float sum = 0;
    double n;
    printf("This program sums a series of double values.\n");
    printf("Enter double value (0 to terminate): ");
    scanf("%lf", &n);
    while ( n!=0){
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %f\n", sum);
    return 0;
}
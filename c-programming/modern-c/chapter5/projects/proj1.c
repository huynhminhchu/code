#include <stdio.h>

int main(){
    int n, digits;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n > 0 && n < 10) {
        digits = 1;
    } else if (n >= 10 && n < 100) {
        digits = 2;
    } else if (n >= 100 && n < 1000) {
        digits = 3;
    }
    printf("The number %d has %d digits\n", n, digits);
}
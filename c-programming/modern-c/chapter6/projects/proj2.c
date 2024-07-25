#include <stdio.h>

int main(void){
    int n, m;
    printf("Enter 2 integers: ");
    scanf("%d %d", &n, &m);
    while (n != 0){
        int r = m%n;
        m = n;
        n = r;
    }
    printf("Greatest common divisor: %d\n", m);
}
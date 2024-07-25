#include <stdio.h>

int gcd(int n, int m){
    while (n != 0){
        int r = m%n;
        m = n;
        n = r;
    }
    return m;
}
int main(void){
    int n, m;
    printf("Enter a fraction: ");
    scanf("%d/%d", &n, &m);
    int g = gcd(n,m);
    printf("In lowest terms: %d/%d\n", n/g,m/g);
}
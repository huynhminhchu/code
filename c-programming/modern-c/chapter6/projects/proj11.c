#include <stdio.h>

int main(){
    int n;
    float e = 1;
    int fact = 1;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        fact *= i;
        e += 1.0f/fact;
    }
    printf("The result e is : %f\n", e);
}
#include <stdio.h>

int main(){
    float n;
    float max = 0;
    while (1){
        printf("Enter a number: ");
        scanf("%f",&n);
        if (n > max)
            max = n;
        if (n == 0)
            break;
    }
    printf("Maxium number: %.2f\n", max);
}
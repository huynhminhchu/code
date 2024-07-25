#include <stdio.h>

// 123 => 321
// 1 => 1
// 4235 => 5424

int main(){
    int n;
    printf("Enter the value :");
    scanf("%d",&n);
    
    do {
        //3
        printf("%d", n%10);
        n = n/10; // n = 12
    } while (n != 0);
    printf("\n");
}
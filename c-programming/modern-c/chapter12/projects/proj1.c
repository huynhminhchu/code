#include <stdio.h>

#define N 1000

int main(void)
{
    char ch;
    char a[N];
    char *p = a;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        *p = ch;
        p++;
    }
    p = p-1;
    for (p; p >= a; p--){
        printf("%c", *p);
    }
    printf("\n");
}
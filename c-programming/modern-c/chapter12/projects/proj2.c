#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define N 1000

int main(void)
{
    char ch;
    char a[N];
    char *p = a;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        if (isalpha(ch)){
            *p = tolower(ch);
            p++;
        }
    }
    p = p-1;
    char *q = a;
    for (p,q; p >= a, q < p; p--, q++ ){
        if (*p != *q){
            printf("Not a palindrome\n");
            exit(EXIT_SUCCESS);
        }
    }

    printf("Palindrome\n");
    exit(EXIT_SUCCESS);
}
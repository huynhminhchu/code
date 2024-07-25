#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_palindrome(const char *message);
int main(void)
{
    printf("hello world\n");
    char *s = "asdsa";
    if (is_palindrome(s)){
        printf("is palindrome\n");
    } else {
        printf("is not palindrome\n");
    }
}

bool is_palindrome(const char *message)
{
    char *p = message;
    char *k = message;
    while (*p != '\0'){
        p++;
    }
    p--;
    while (k != p)
    {
        printf("k: %c\n", *k);
        printf("p: %c\n", *p);
        if (*k != *p)
            return false;
        k++;
        p--;
    }
    return true;
}
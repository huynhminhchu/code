#include <stdio.h>

int count_spaces(const char *s);

int main(void)
{
    char s[] = "hello world darkness!";
    printf("Spaces in this string: %d\n", count_spaces(s));
}

int count_spaces(const char *s)
{
    int count = 0;
    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;
}
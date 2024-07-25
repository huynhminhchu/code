#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *concat(const char *s1, const char *s2)
{
    char *s = malloc(strlen(s1) + strlen(s2) + 1);
    if (s == NULL){
        printf("Cant allocate memory, exiting ...\n");
        exit(EXIT_FAILURE);
    }
    strcpy(s, s1);
    strcat(s, s2);
    return s;
}

int main(void)
{
    char *s1 = "hello";
    char *s2 = " world";
    printf("Concat test: %s\n", concat(s1,s2));
}
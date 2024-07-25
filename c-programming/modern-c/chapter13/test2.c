#include <stdio.h>
#include <string.h>

int main() {
    // Declare an array of strings
    char s1[] = "hello world";
    char s2[] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    printf("Compare result: %d\n", strcmp(s1,s2));
}
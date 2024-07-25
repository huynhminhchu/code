#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = argc - 1; i >= 1; i--){
        printf("%s\t", argv[i]);
    }
    printf("\n");

    char **p;
    for (p = argv + argc - 1; *p > argv; p--){
        printf("%s ", *p);
    }
    printf("\n");

}
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "example.txt"

int main(void)
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL){
        printf("Can't open %s\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    //Do something
    fclose(fp);
    return 0;
}
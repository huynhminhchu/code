#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 1; i < argc ; i++){
        int value = atoi(argv[i]);
        sum += value;
    }
    printf("Total value: %d\n", sum);
}
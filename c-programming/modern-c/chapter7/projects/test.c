#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int command;
    printf("Enter an integer: ");
    scanf("%d", &i);
    printf("Enter a command: ");
    command = getchar();
    return 0;
}
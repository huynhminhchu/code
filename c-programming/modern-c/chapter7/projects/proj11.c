#include <stdio.h>

int main(){
    int c, initial_char;
    printf("Enter a first and last name: ");
    while ((c = getchar()) == ' '){

    }
    initial_char = c;
    while ((c = getchar()) != ' '){
    }
    while ((c = getchar()) != '\n'){
        printf("%c",c);
    }
    printf(", %c.\n", initial_char);
    return 0;
}
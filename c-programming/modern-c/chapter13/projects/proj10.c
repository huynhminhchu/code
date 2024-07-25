#include <stdio.h>
#include <string.h>
// The function expects name to point to a string containing a first name followed by a last
// name. It modifies the string so that the last name comes first, followed by a comma, a space,
// the first initial, and a period. The original string may contain extra spaces before the first
// name, between the first and last names, and after the last name.

// chu huynh => huynh, c.

#define SIZE 100;
void reverse_name(char *name)
{
    char *p = name;
    char init_char = name[0];


    while ((*p != '\0') && (*p != ' ')){
        p++;
    }
    p++;
    while (*p != '\0'){
        putchar(*p++);
    }
    printf(", %c\n", init_char);
}

int main(){
    // int c, initial_char;
    // printf("Enter a first and last name: ");
    // while ((c = getchar()) == ' '){

    // }
    // initial_char = c;
    // while ((c = getchar()) != ' '){
    // }
    // while ((c = getchar()) != '\n'){
    //     printf("%c",c);
    // }
    // printf(", %c.\n", initial_char);

    char *s = "chu huynh";
    reverse_name(s);
    printf("origin string: %s\n", s);
    return 0;
}
#include <stdbool.h>
#include <stdio.h>
#include "stackADT.h"


int main(void)
{
    Stack stack = create();
    char ch;
    while ((ch = getchar()) != '\n'){
        if (ch == ')'){
            char temp_ch = pop(stack);
            if (temp_ch != '('){
                push(stack, temp_ch);
                push(stack, ch);
            }
        } else if (ch == '}'){
            char temp_ch = pop(stack);
            if (temp_ch != '{'){
                push(stack, temp_ch);
                push(stack, ch);
            }
        } else {
            push(stack, ch);
        }

    }
    if (is_empty(stack))
        printf("Nested properly\n");
    else    
        printf("Nested not properly\n");

}

/*
((){}{()})
Nested properly

(}()
Nested not properly
*/
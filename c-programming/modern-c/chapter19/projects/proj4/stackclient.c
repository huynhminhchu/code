#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s1, s2;
    
    char *str_ptr1 = "hello world";
    char *str_ptr2 = "goodbye";

    s1 = create();
    s2 = create();

    push(s1, str_ptr1);
    push(s1, str_ptr2);
    char *temp_ptr = pop(s1);

    printf("Value: %s\n", temp_ptr);

    // push(s2, n);
    // n = pop(s1);
    // printf("Popped %d from s1\n", n);
    // push(s2, n);
    // destroy(s1);
    // while (!is_empty(s2))
    //     printf("Popped %d from s2\n", pop(s2));
    // push(s2, 3);
    // make_empty(s2);
    // if (is_empty(s2))
    //     printf("s2 is empty\n");
    // else
    // printf("s2 is not empty\n");
    // destroy(s2);
    return 0;
}
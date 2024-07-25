#include <stdbool.h>
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    Stack stack = create();
    char ch;
    for (;;){
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n'){
            if (ch == 'q')
                return 0;
            if (isdigit(ch)){
                push(stack, (int) (ch - '0'));
            } else if (ch == '='){
                printf("Value of expression: %d\n", pop(stack));
                make_empty(stack);
            } else {
                int operand2 = pop(stack);
                int operand1 = pop(stack);
                int result;
                switch (ch)
                {
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                default:
                    result = 0;
                    break;
                }
                push(stack, result);
            }
        }
    }

    
}
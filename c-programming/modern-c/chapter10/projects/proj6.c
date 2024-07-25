#include <stdbool.h>
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);

int main(void)
{
    char ch;
    for (;;){
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n'){
            if (isdigit(ch)){
                push((int) (ch - '0'));
            } else if (ch == '='){
                printf("Value of expression: %d\n", pop());
                make_empty();
            } else {
                int operand2 = pop();
                int operand1 = pop();
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
                push(result);
            }
        }
    }

    
}


void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full()){
        printf("Expression is too complex.\n");
        exit(EXIT_FAILURE);
    } else contents[top++] = i;
}

int pop(void)
{
    if (is_empty()){
        printf("Not enough operands in expression.\n");
        exit(EXIT_FAILURE);
    }
    else return contents[--top];
}
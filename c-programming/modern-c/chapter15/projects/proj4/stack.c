#include <stdio.h>
#include "stack.h"


#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

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
    if (is_full())
        printf("Stack overflow\n");
    else 
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty()){
        printf("Stack underflow\n");
        return -1;
    }
    else
        return contents[--top];
}
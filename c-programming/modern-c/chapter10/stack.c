#include <stdbool.h>
#include <stdio.h>

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
    push(100);
    push(55);
    int n = pop();
    printf("Value of n = %d\n", n);
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
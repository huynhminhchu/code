#include "stack.h"

int contents[100];
int top = 0;

void make_empty(void)
{
    top = 0;
}
int is_empty(void)
{
    return (top == 0);
}
int is_full(void)
{
    return (top == 100);
}
void push(int i)
{
    contents[top++] = i;
}
int pop(void)
{
    top--;
}

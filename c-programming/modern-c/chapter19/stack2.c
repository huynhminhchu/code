#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    int data;
    struct node *next;
};

static struct node *top = NULL;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while (!is_empty())
        pop();
}
bool is_empty(void)
{
    return top == NULL;
}
bool is_full(void)
{
    return false;
}
void push(int i)
{
    struct node *p = malloc(sizeof(struct node));
    if (p == NULL)
        terminate("Error in push: stack is full.");
    p->data = i;
    p->next = top;
    top = p;
}
int pop(void)
{
    int i;
    if (is_empty())
        terminate("Error in pop: stack empty.");
    struct node *p = top;
    top = top->next;
    i = p->data;
    free(p);
    return i;
}
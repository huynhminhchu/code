#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);

int main(void)
{
    char ch;
    while ((ch = getchar()) != '\n'){
        if (ch == ')'){
            char temp_ch = pop();
            if (temp_ch != '('){
                push(temp_ch);
                push(ch);
            }
        } else if (ch == '}'){
            char temp_ch = pop();
            if (temp_ch != '{'){
                push(temp_ch);
                push(ch);
            }
        } else {
            push(ch);
        }

    }
    if (is_empty())
        printf("Nested properly\n");
    else    
        printf("Nested not properly\n");

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

void push(char c)
{
    if (is_full())
        printf("Stack overflow\n");
    else 
        contents[top++] = c;
}

char pop(void)
{
    if (is_empty()){
        printf("Stack underflow\n");
        return '\0';
    }
    else
        return contents[--top];
}
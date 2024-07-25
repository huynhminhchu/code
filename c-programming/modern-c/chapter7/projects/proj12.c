#include <stdio.h>
#include <ctype.h>



int main(){
    char c;
    float n1, n2;
    char current_operator;

    printf("Enter an expression: ");
    scanf("%f", &n1);

    while ((c = getchar()) != '\n'){
        switch(c){
            case '+':
                scanf("%f", &n2);
                n1 += n2;
                break;
            case '-':
                scanf("%f", &n2);
                n1 -= n2;
                break;
            case '*':
                scanf("%f", &n2);
                n1 *= n2;
                break;
            case '/':
                scanf("%f", &n2);
                n1 /= n2;
                break;
            default:
                continue;
        }
    }
    printf("Value of expression: %.2f\n", n1);
    return 0;
}
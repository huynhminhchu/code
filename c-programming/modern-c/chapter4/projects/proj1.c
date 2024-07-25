#include <stdio.h>

int main(){
    int num, firstNum, secondNum;
    printf("Enter a two-digit number: ");
    scanf("%d", &num);
    firstNum = num%10;
    secondNum = num/10;
    printf("The reversal is: %d%d\n",firstNum,secondNum);

}
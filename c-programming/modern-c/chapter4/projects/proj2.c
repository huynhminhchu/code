#include <stdio.h>

int main(){
    int num, firstNum, secondNum, thirdNum;
    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    if (num/100 > 0){
        thirdNum = num/100;
    } else {
        thirdNum = 0;
    }
    num = num%100;
    firstNum = num%10;
    secondNum = num/10;
    printf("The reversal is: %d%d%.0d\n",firstNum,secondNum,thirdNum);

}
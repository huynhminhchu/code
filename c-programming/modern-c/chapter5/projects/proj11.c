#include <stdio.h>

int main(void)
{
    char *first_digit[] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *second_digit[]  = {"one", "two", "three", "four", "five", "six", "sven", "eight", "nine"};
    char *number[] ;
    int first, second;
    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &first, &second);

    if (first == 1){
        second_digit[0] = "eleven";
        second_digit[1] = "twelve";
        second_digit[2] = "thirteen";
        second_digit[3] = "fourteen";
        second_digit[4] = "fifteen";
        second_digit[5]  = "sixteen";
        second_digit[6] = "seventeen";
        second_digit[7] = "eighteen";
        second_digit[8] = "nineteen";
    }

    printf("You entered the number %s-%s\n", first_digit[first-2], second_digit[second-1]);
}
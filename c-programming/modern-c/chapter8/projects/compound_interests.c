#include <stdio.h>


int main(void){
    int interest_rate, years;
    printf("Enter interest rate: ");
    scanf("%d", &interest_rate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("Years\t");
    for (int i = interest_rate; i < interest_rate + 5; i++)
    {
        printf("%d%%\t", i);
        /* code */
    }
    // printf("Goodbye world\n");
    
    return 0;
}
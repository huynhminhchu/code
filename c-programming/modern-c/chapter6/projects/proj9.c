#include <stdio.h>

int main() {
    float loan, interestRate, monthlyPayment, balanceRemaining;
    int number_of_payments;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    printf("Enter the number of payments: ");
    scanf("%d", &number_of_payments);

    for (int i = 0; i < number_of_payments; i++){
        loan = (loan - monthlyPayment) + (interestRate/12.0f * loan/100.0f);
        printf("Balance remaining after payment %d: %.2f\n", i+1, loan);
    }
    
}
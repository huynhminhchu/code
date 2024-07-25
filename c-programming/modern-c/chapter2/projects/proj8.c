#include <stdio.h>

int main() {
    float loan, interestRate, monthlyPayment, balanceRemaining;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);
    loan = (loan - monthlyPayment) + (interestRate/12.0f * loan/100.0f);
    printf("Balance remaining after first payment: %.2f\n", loan);
    loan = (loan - monthlyPayment) + (interestRate/12.0f * loan/100.0f);
    printf("Balance remaining after second payment: %.2f\n", loan);
    loan = (loan - monthlyPayment) + (interestRate/12.0f * loan/100.0f);
    printf("Balance remaining after third payment: %.2f\n", loan);
}
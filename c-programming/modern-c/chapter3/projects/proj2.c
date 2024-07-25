#include <stdio.h>

int main(){
    int itemNumber;
    float unitPrice;
    int mm,dd,yyyy;
    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    printf("Enter unit price: ");
    scanf("%f", &unitPrice);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);
    printf("\n");
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%6.2f\t\t%.2d/%.2d/%.4d\n", itemNumber, unitPrice, mm, dd, yyyy);

}
#include <stdio.h>

int main(){
    int gs1Prefix, groupId, publisherCode, itemNumber, checkDigit;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1Prefix, &groupId, &publisherCode, &itemNumber, &checkDigit);
    printf("GS1 prefix: %3.3d\n",gs1Prefix);
    printf("Group identifier: %2.2d\n",groupId);
    printf("Publisher code: %5.5d\n", publisherCode);
    printf("Item number: %d\n", itemNumber);
    printf("Check digit: %d\n", checkDigit);
    return 0;
}
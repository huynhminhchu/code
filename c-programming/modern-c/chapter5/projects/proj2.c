#include <stdio.h>

int main(){
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%2d:%2d", &hour, &minute);

    if (hour >= 1 && hour <= 11){
        printf("Equivalent 12-hour time: %2.2d:%d AM\n", hour, minute);
    } else if (hour == 12){
        printf("Equivalent 12-hour time: %2.2d:%d PM\n", hour, minute);
    } else if (hour >= 13 && hour <= 23){
        printf("Equivalent 12-hour time: %.2d:%.2d PM\n", hour-12, minute);
    } else if (hour == 0) {
        printf("Equivalent 12-hour time: %.2d:%.2d AM\n", hour+12, minute);
    }

}
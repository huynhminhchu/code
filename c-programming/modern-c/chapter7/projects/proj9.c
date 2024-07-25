#include <stdio.h>
#include <ctype.h>

int main(){
    int hour, minute;
    char periodIndicator;
    printf("Enter a 12-hour-time: ");
    scanf("%d:%d %c", &hour, &minute, &periodIndicator) ;
    periodIndicator = toupper(periodIndicator);
    if (periodIndicator == 'A'){
        if (hour == 12){
            hour = hour - 12;
        }
    } else if (periodIndicator == 'P'){
        hour += 12;
    }
    printf("Equivalent 24-hour time: %d:%d\n", hour, minute);
    return 0;
}
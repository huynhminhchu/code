#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *months[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };

    int mm,dd,yyyy;
    printf("Enter a date (mm/dd/yy): ");
    scanf("%2d/%2d/%4d", &mm, &dd, &yyyy);

    printf("You entered the date %s %d, %d\n", months[mm-1], dd, yyyy);
}


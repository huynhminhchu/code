#include <stdio.h>

int main(){
    int first, second, third;
    printf("Enter phone number [(xxx) xxx-xxxx] :");
    scanf("(%d) %d-%d", &first, &second, &third);
    printf("You entered %3.3d.%3.3d.%4.4d\n", first, second, third);
    
}
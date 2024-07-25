#include <stdio.h>

int minutes_since_midnight(int hour, int minute){
    return hour*60 + minute;
}
int main(){
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d",&hour,&minute);

    
}
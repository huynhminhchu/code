#include <stdio.h>

#define PI 3.14

int main(){
    int r;
    printf("Enter the radius of the sphere: \n");
    scanf("%d", &r);

    float volume = 4.0f/3.0f*PI*r*r*r;
    printf("Volume = %f\n", volume);
}
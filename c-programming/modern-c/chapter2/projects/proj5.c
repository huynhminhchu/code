#include <stdio.h>

int exp(int x, int n){
    //Calculate x^n, n not negative
    int result = 1;
    for (int i = 0; i < n; i++){
        result *= x;
    }
    return result;

}
int main(){
    int x;
    printf("Enter the x value: ");
    scanf("%d",&x);
    int polynomial = 3*exp(x,5) + 2*exp(x,4) - 5*exp(x,3) - exp(x,2) + 7*x -6;
    printf("Polynomial: %d\n", polynomial);
}
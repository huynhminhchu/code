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
    int polynomial = (((((3*x+2)*x-5))*x-1)*x+7)*x-6;
    printf("Polynomial: %d\n", polynomial);
}
#include <stdio.h>

int main(){
    int a[15] = {[2] = 29, [9] = 7, [14] = 48};

    for (int i = 0; i < 15; i++){
        printf("%d\t", a[i]);
    }
    return 0;
}
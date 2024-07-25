#include <stdio.h>

int main(){
    int mm,dd,yy;
    int min_mm = 99, min_dd =99, min_yy = 99;

    do {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &mm,&dd,&yy);
        if (mm == 0 && dd == 0 && yy == 0)
            break;
        if (yy < min_yy){
            min_yy = yy;
            min_dd = dd;
            min_mm = mm;
        } else if (yy == min_yy){
            if (mm < min_mm) {
                min_yy = yy;
                min_dd = dd;
                min_mm = mm;
            } else if (mm == min_mm){
                if (dd < min_dd){
                    min_yy = yy;
                    min_dd = dd;
                    min_mm = mm;
                } 
            } 
        } 
    } while (1);
    printf("%2.2d/%2.2d/%2.2d is the earliest date\n", min_mm, min_dd, min_yy);

}
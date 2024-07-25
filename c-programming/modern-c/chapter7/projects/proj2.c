#include <stdio.h>

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(void){
    int i,n;
    printf("this program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d",&n);
    clean_stdin();
    for (i = 1; i<= n; i++){
        if (i%24 == 0){
            printf("Press ENTER to continue...\n");
            while (getchar() != '\n'){
            } 
        }
        printf("%10d%10d\n", i, i*i);
    }
    return 0;
}
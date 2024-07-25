#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    if (argc != 2){
        printf("Usage: convert filename\n");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1],"r")) == NULL){
        printf("%s can't not be opened\n.", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((c = getc(fp)) != EOF){
        if (isalpha(c))
            c = toupper(c);
        if (putc(c, stdout) == EOF)
            perror("Error with char \n");
    }


    return 0;
}
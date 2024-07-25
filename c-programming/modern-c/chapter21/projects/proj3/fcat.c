#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    if (argc < 2){
        printf("Usage: canopen filename1 filename2\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1 ; i< argc; i++){
        if ((fp = fopen(argv[i], "r")) == NULL){
            printf("%s can't be opened, skipping\n", argv[i]);
            continue;
        }
        while ((c = getc(fp)) != EOF){
            if (putc(c, stdout) == EOF)
                perror("Error with char \n");
        }
    }
    fclose(fp);

}
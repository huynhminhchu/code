#include <stdio.h>

int main()
{
    FILE *fp;
    char str[] = "This is a test string.";

    fp = fopen("test.txt", "w");
    if (fp == NULL){
        perror("Error opening file.");
        return -1;
    }
    fputs(str, fp);
    if (fflush(fp) != 0){
        perror("Error flushing file");
        return -1;
    }
    fclose(fp); 
    //We don't use fflush, buffer is automatically flushed when its fulled or the file is closed
}
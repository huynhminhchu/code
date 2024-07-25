#include <stdio.h>

int main() {
    FILE *fp;

    // Open a file for writing
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Redirect stdout to output.txt
    freopen("output.txt", "w", stdout);

    // Now stdout is redirected, so any printf statements will go to output.txt
    printf("This is redirected to output.txt\n");

    // Close the file
    fclose(fp);

    // Restore stdout to the original stream (typically the console)
    freopen("/dev/tty", "w", stdout);  // On Unix-like systems
    // OR
    // freopen("CONOUT$", "w", stdout); // On Windows

    // Now stdout is back to the console
    printf("This is back to the console\n");

    return 0;
}

#include <stdio.h>
#include <ctype.h>

int main(){
    printf("Enter a sentence: ");
    int count_vowels = 0;
    int c;
    while ((c = getchar()) != '\n'){
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count_vowels++;
        }

    }
    printf("Your sentence contains %d vowels\n", count_vowels);
}
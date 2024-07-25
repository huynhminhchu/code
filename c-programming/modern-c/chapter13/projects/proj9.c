#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int compute_vowel_count(const char *sentence);
int main(){
    char *s = (char*) malloc(SIZE);

    printf("Enter a sentence: ");
    fgets(s, SIZE, stdin);

    printf("Sentence: %s\n", s);
    int count_vowels = compute_vowel_count(s);
    printf("Your sentence contains %d vowels\n", count_vowels);
}

int compute_vowel_count(const char *sentence)
{
    int c;
    int count_vowels = 0;
    for (; *sentence != '\0'; sentence++)
    {
        c = tolower(*sentence);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count_vowels++;
        }
    }
    return count_vowels;
}
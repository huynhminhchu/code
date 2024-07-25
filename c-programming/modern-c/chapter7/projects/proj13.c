#include <stdio.h>

int main(){
    float total_char = 0.0f, total_word = 0.0f;
    char c;
    printf("Enter a sentence: ");
    while ( (c = getchar()) != '\n'){
        if (c == ' '){
            total_word++;
            continue;
        }
        total_char++;

    }
    total_word++;
    printf("Average word length: %.1f\n", total_char/total_word);
}
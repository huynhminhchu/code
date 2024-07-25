#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define SIZE 100

char current_word[SIZE+1];
char smallest_word[SIZE+1];
char largest_word[SIZE+1];

void input_word(void)
{
    printf("Enter word: ");
    scanf("%s", current_word);
}
int main(void)
{
    input_word();
    strcpy(smallest_word, current_word);
    strcpy(largest_word, current_word);
    while (true){
        input_word();
        if (strcmp(largest_word, current_word) < 0)
            strcpy(largest_word, current_word);
        if (strcmp(smallest_word, current_word) > 0)
            strcpy(smallest_word, current_word);
        if (strlen(current_word) == 4){
            break;
        }
    }
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char *read_line(void)
{
    char c;
    int i = 0;
    char *word = malloc(20 * sizeof(char));

    while (isspace(c = getchar())){
        if (c == '\n')
            return NULL;
    }
    while (c != '\n' && c != EOF){
        if (i < 20)
            word[i++] = c;
        c = getchar();
    }

    word[i] = '\0';
    return word;
}

void print_words(char *word[], int num_words)
{
    for (int i = 0; i < num_words; i++){
        printf("Word #%d: %s\n", i + 1, word[i]);
    }
}

int cmp_str(const void *a, const void *b)
{
    // return ((part *) a)->number - ((part *) b)->number;

    //if we pass const char *a to compare function in qsort, it will be cast as const char **a (address of const char *a)
   const char *aa = *(const char **)a; // aka value of string a
   const char *bb = *(const char **)b; // aka value of string b;


   return strcmp(aa, bb);

   
}

int main(void)
{
    char *word[100];

    int num_word = 0;

    while(true){
        printf("Enter word: ");
        word[num_word] = malloc(20 * sizeof(char));
        word[num_word] = read_line();
        if (word[num_word] == NULL){
            break;
        }
        num_word++;
    }
    qsort(word, num_word, sizeof(char *), cmp_str);
    /*
    void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

    int (*compar)(const void *, const void *) or cmp_str in this case: a function comparison that takes address of 2 elements as inputs.

    an element of char *word[100] is char *;

    https://stackoverflow.com/questions/3757899/sorting-strings-using-qsort
    https://benjaminwuethrich.dev/2015-03-07-sorting-strings-in-c-with-qsort.html
    */
    print_words(word, num_word);
}
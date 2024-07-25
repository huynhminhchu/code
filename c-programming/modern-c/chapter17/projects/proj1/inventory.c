#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

typedef struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part;

part *inventory;

int num_parts = 0; 
int max_parts = 1;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int compare_parts(const void *a, const void *b){
    return ((part *) a)->number - ((part *) b)->number;
}

int main(void)
{
    char code;
    int max_parts = 10;
    inventory = (part *)malloc(max_parts * sizeof(part));
    for (;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
            break;
        }
        printf("\n");   
    }
}

int find_part(int number)
{
    int i;
    for (i = 0 ; i < num_parts; i++){
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}
void insert(void)
{
    int number;
    int on_hand;

    printf("Enter part number: ");
    scanf(" %d", &number);
    if (find_part(number) != -1){
        printf("Part already exists.\n");
        return;
    }

    if (num_parts == max_parts - 1){
        inventory = (part *)realloc(inventory, num_parts * 2);
    }

    inventory[num_parts].number = number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}
void search(void)
{
    int number, i;

    printf("Enter part number: ");
    scanf(" %d", &number);
    i = find_part(number);
    if (i < 0){
        printf("Part not found.\n");
    } else {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
}
void update(void)
{
    int number, i, change;
    printf("Enter part number: ");
    scanf(" %d", &number);
    i = find_part(number);
    if (i < 0){
        printf("Part not found.\n");
    } else {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
}
void print(void)
{
    printf("Part Number     Part Name                                       "
            "Quantity on Hand\n");
    qsort(inventory, num_parts, sizeof(part), compare_parts);
    for (int i = 0 ; i < num_parts; i++){
        printf("%7d         %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }
}
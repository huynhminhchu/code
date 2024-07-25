#include <stdio.h>
#include "readline.h"
#include "inventory.h"
#include "quicksort.h"

#define MAX_PARTS 100

int main(void)
{
    int num_parts = 0; 
    struct part inventory[MAX_PARTS];
    char code;
    for (;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code)
        {
        case 'i':
            insert(inventory, &num_parts);
            organize_inventory(inventory, num_parts);
            break;
        case 's':
            search(inventory, num_parts);
            break;
        case 'u':
            update(inventory, num_parts);
            break;
        case 'p':
            print(inventory, num_parts);
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

int find_part(const struct part *inventory, int num_parts, int number)
{
    int i;
    for (i = 0 ; i < num_parts; i++){
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}
void insert(struct part *inventory, int *num_parts)
{
    int number;
    int on_hand;

    printf("Enter part number: ");
    scanf(" %d", &number);
    if (find_part(inventory, *num_parts, number) != -1){
        printf("Part already exists.\n");
        return;
    }
    inventory[*num_parts].number = number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);

    printf("Enter part price: ");
    scanf("%lf", &inventory[*num_parts].price);

    (*num_parts)++;

}
void search(struct part *inventory, int num_parts)
{
    int number, i;

    printf("Enter part number: ");
    scanf(" %d", &number);
    i = find_part(inventory, num_parts, number);
    if (i < 0){
        printf("Part not found.\n");
    } else {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
        printf("Price: %.2f\n", inventory[i].price);
    }
}
void update(struct part *inventory, int num_parts)
{
    int number, i, change;
    printf("Enter part number: ");
    scanf(" %d", &number);
    i = find_part(inventory, num_parts, number);
    if (i < 0){
        printf("Part not found.\n");
    } else {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
}
void print(struct part *inventory, int num_parts)
{
    printf("Part Number     Part Name       Part Price                     "
            "Quantity on Hand\n");
    for (int i = 0 ; i < num_parts; i++){
        printf("%7d         %-25s%7f%11d\n", inventory[i].number, inventory[i].name, inventory[i].price,inventory[i].on_hand);
    }
}

void organize_inventory(struct part *inventory, int num_parts)
{
	quicksort(inventory, 0, num_parts-1);
}
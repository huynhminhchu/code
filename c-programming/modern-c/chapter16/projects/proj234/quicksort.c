#include "quicksort.h"
#include "inventory.h"
#include <string.h>
#include <stdio.h>


void quicksort(struct part *a, int low, int high)
{
    int middle;
    if (low >= high)
        return;
    middle = partition(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

void swap(struct part *a, struct part *b)
{
    if (a == b){
        return;
    }
    struct part temp;
    strcpy(temp.name, a->name);
    temp.number = a->number;
    temp.on_hand = a->on_hand;

    strcpy(a->name, b->name);
    a->number = b->number;
    a->on_hand = b->on_hand;

    strcpy(b->name, temp.name);
    b->number = temp.number;
    b->on_hand = temp.on_hand;
}

int partition(struct part *a, int low, int high)
{
    struct part pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (a[j].number <= pivot.number) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i + 1;
}
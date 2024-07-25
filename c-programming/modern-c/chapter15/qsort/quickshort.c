#include "quickshort.h"

void quicksort(int a[], int low, int high)
{
    int middle;
    if (low >= high)
        return;
    middle = partition(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (a[j] <= pivot) {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i + 1;
}
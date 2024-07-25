#ifndef QUICKSHORT_H
#define QUICKSHORT_H

#include "inventory.h"
void quicksort(struct part *a, int low, int high);
void swap(struct part *a, struct part *b);
int partition(struct part *a, int low, int high);

#endif
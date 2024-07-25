#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue_type *Queue;
typedef int Item;

void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek_front(Queue q);
Item peek_rear(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void destroy(Queue q);
Queue create(int size);
void empty_queue(Queue q);

#endif
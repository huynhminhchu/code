#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100


/*
<-(dequeue) Front - 3 -4 -4 -5 -6 <- (enqueue) Rear

a[100] <- a[0]
*/
struct queue_type {
    Item contents[QUEUE_SIZE];
    int front,rear;
    int total;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    q->front = 0;
    q->rear = 0;
    q->total = 0;
    return q;
}

/*
Insert an element at the end of the eue i.e at the rear end
*/
void enqueue(Queue q, Item i)
{
    if (is_full(q))
        terminate("Error in enqueue: queue is full.");
    q->contents[q->rear++] = i;
    q->total += 1;
}
/*
This operation removes and returns an element that is at the front end of the queue.
*/
Item dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in dequeue: queue is full.");
    
    if (q->front == q->rear){
        q->front = q->rear = 0;
        q->total = 0;
    }
    Item i = q->contents[q->front++];
    q->total -= 1;
    return i;
}
Item peek_front(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek front: empty q");
    return q->contents[q->front];
}
Item peek_rear(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek rear: empty q");
    return q->contents[q->rear - 1];
}
bool is_empty(Queue q)
{
    return q->total == 0;
}
bool is_full(Queue q)
{
    return q->total == QUEUE_SIZE;
}

void destroy(Queue q)
{
    free(q);
}

void empty_queue(Queue q)
{
    while (!is_empty(q))
        dequeue(q);
}

#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

/*
<-(dequeue) Front - 3 -4 -4 -5 -6 <- (enqueue) Rear

a[100] <- a[0]
*/

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *rear;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

struct node *create_node(Item data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Queue create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in creating stack.");
    q->front = q->rear = NULL;
    return q;
}

/*
Insert an element at the end of the eue i.e at the rear end
*/
void enqueue(Queue q, Item i)
{
    if (is_full(q))
        terminate("Error in enqueue: queue is full.");
    struct node *new_node = create_node(i);
    if (is_empty(q)){
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}
/*
This operation removes and returns an element that is at the front end of the queue.
*/
Item dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in dequeue: queue is full.");
    
    struct node *old_front = q->front;
    Item i = q->front->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
    free(old_front);
    return i;
}
Item peek_front(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek front: empty q");
    return q->front->data;
}
Item peek_rear(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek rear: empty q");
    return q->rear->data;
}
bool is_empty(Queue q)
{
    return (q->front == NULL && q->rear == NULL);
}
bool is_full(Queue q)
{
    return false;
}

void destroy(Queue q)
{
    free(q);
}

void empty_queue(Queue q)
{
    while (!is_empty(q)){
        dequeue(q);
    }
}

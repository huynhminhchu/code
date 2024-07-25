#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode {
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode *head);
void InsertInLinkedList(struct ListNode *head, int data, int position); 


int main(void)
{

}
int ListLength(struct ListNode *head){

    /*
    Time Complexity: O(n), for scanning the list of size n.
    Space Complexity: O(1), for creating a temporary variable.
    */

    int length = 0;
    struct ListNode *current;
    current = head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void InsertInLinkedList(struct ListNode *head, int data, int position)
{
    /*
    • Inserting a new node before the head (at the beginning)
    • Inserting a new node after the tail (at the end of the list)
    • Inserting a new node at the middle of the list (random location)
    */
    struct ListNode *newNode;
    newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (!newNode){
        printf("Memory Error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

    if (position == 1) {
        // Insert before the head
        newNode->next = head;
        head = newNode;
        return;
    }


}
#ifndef SLL_H // guard
#define SLL_H

struct Node
{
    int el; // we use ints for now
    struct Node *next;
};
typedef struct Node Node; // Node for SLL

// SLL Functions

void insertFirst(Node **head, int element);
void insertLast(Node **head, int element);
void deleteFirst(Node **head);
void deleteLast(Node **head);
Node *findElement(Node **head, int element);
void deleteElement(Node **head, int element);

#endif

#include <stdlib.h>
#include "singly_linked_list.h"

/*
Arguments:
Node** head - Pointer to The head pointer
int element - The element to be inserted.
Returns: Nothing.
Synopsis:
Inserts an element at the beginning.
*/
void insertFirst(Node **head, int element)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->el = element;
    newNode->next = *head;
    *head = newNode;
}

/*
Arguments:
Node** head - Pointer to The head pointer
int element - The element to be inserted.
Returns: Nothing.
Synopsis:
Inserts an element at the end.
*/
void insertLast(Node **head, int element)
{
    // TODO: Fix This. Somehow we insert a node at the head that points to the node we insert here, ONLY WHEN HEAD IS NULL
    Node *newNode = malloc(sizeof(Node));
    newNode->el = element;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

/*
Arguments:
Node** head - Pointer to The head pointer
Returns: Nothing
Synopsis:
Deletes the First Element
*/
void deleteFirst(Node **head)
{
    if (*head == NULL)
        return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

/*
Arguments:
Node** head - Pointer to The head pointer
Returns: Nothing
Synopsis:
Deletes the Last Element
*/
void deleteLast(Node **head)
{
    if (*head == NULL)
        return;
    if ((*head)->next == NULL)
    {
        Node *temp = *head;
        *head = NULL;
        free(temp);
        // free(*head); // this causes an error(crazy value of head->el) for some reason
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    Node *deletedNode = temp->next;
    temp->next = NULL;
    free(deletedNode);
}

/*
Arguments:
Node** head - Pointer to The head pointer
int element - The value stored in the node to be found.
Returns: Pointer to Node.
Synopsis:
Returns the pointer to the node with the element if found; returns NULL otherwise.
*/
Node *findElement(Node **head, int element)
{
    Node *temp = *head;
    while (temp->el != element && temp != NULL)
        temp = temp->next;
    return temp;
}

void deleteElement(Node **head, int element)
{
    Node *temp = *head;
    while (temp != NULL && temp->next->el != element)
        temp = temp->next;
    if (temp == NULL)
        return;
    Node *deleted = temp->next;
    temp->next = temp->next->next;
    free(deleted);
}

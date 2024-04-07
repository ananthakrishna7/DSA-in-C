#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

int main()
{
    Node *head = malloc(sizeof(Node));
    int elements;
    printf("Enter number of elements: ");
    scanf("%d", &elements);
    int elmt;
    printf("Enter element 0: ");
    scanf("%d", &elmt);
    insertLast(&head, elmt);
    deleteFirst(&head); // for some reason insertLast() inserts an element with el=0 at the head.
    for (int i = 1; i < elements; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &elmt);
        insertLast(&head, elmt);
    }

    // Menu driven
    Node *temp;
    int choice;
    int elt;
    while (1)
    {
        printf("Options:\n[0] Print the Linked List\n[1] Insert an element at the beginning\n[2] Insert an element at the end\n[3] Remove the first element\n[4] Remove the last element\n[5] Remove the first occurrence of a particular element\n[6] Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->el);
                temp = temp->next;
            }
            printf("\n");
            break;

        case 1:
            printf("Enter the element: ");
            scanf("%d", &elt);
            insertFirst(&head, elt);
            break;

        case 2:
            printf("Enter the element: ");
            scanf("%d", &elt);
            insertLast(&head, elt);
            break;

        case 3:
            deleteFirst(&head);
            printf("First element deleted.\n");
            break;

        case 4:
            deleteLast(&head);
            printf("Last element deleted.\n");
            break;

        case 5:
            printf("Enter the element: ");
            scanf("%d", &elt);
            deleteElement(&head, elt);
            printf("%d was deleted.\n", elt);
            break;

        default:
            return 0;
        }
    }
}

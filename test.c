#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	insertLast(&head, 20);
	printf("%d", head->el);
	return 0;
}

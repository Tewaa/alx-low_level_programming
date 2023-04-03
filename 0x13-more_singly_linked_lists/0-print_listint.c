#include "lists.h"

/**
 *prints_listint - prints all singly list elements
 *@n-prints nodes
 *
 *Return:the number of nodes
*/
size_t print_listint(const listint_t *h);
{
	size_t num = 0;

while (h != NULL)
{
printf("%d\n", h->n);
num++;
h = h->next;
}
return (num);
}


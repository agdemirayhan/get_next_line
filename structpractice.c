#include <stdio.h>
#include <stdlib.h>

struct				node
{
	int				value;
	struct node		*next;
};
typedef struct node	node_t;

void	printlist(node_t *head)
{
	node_t	*temphead;

	temphead = head;
	while (temphead)
	{
		printf("%d - ", temphead->value);
		temphead = temphead->next;
	}
	printf("\n");
}

node_t *create_new_node(int value)
{
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;

	return result;
}

int	main(void)
{
	node_t *n1, n2, n3;
	node_t *head;

	n1 = malloc(sizeof(node_t));
	n1->value = 1;
	n2.value = 2;
	n3.value = 3;

	// link the list
	head = n1;
	n3.next = NULL;
	n2.next = &n3;
	n1->next = &n2;

	printlist(head);

	return (0);
}
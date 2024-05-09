#include <stdio.h>

struct node {
	int value;
	struct node *next;
};
typedef struct node node_t;

void printlist(node_t *head)
{
	node_t *temphead = head;

	while (temphead)
	{
		printf("%d - ",temphead->value);
		temphead = temphead ->next;
	}
	printf("\n");
}

int main(void)
{

	node_t n1, n2, n3;
	node_t *head;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;

	// link the list
	head = &n3;
	n3.next = &n2;
	n2.next = &n1;
	n1.next = NULL;

	node_t n4;
	n4.value = 4;

	head = &n4;
	n4.next = &n3;


	printlist(head);

	return 0;
}
#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};
typedef struct node node_t;

int main()
{
	node_t n1,n2,n3;
	node_t *head;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;

	head = &n3;
	n3.next = &n2;
	n2.next = &n1;
	n1.next = NULL;

}
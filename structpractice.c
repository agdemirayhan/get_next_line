#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

struct				node
{
	char			*string;
	struct node		*next;
};
typedef struct node	node_t;



int	main(void)
{
	char *buffer;
	node_t *node;
	node_t *head;
	int readed;
	int fd;

	buffer = malloc((BUFFER_SIZE +1) * sizeof(char));
	head = malloc(sizeof(node_t));

	fd = open("test.txt",O_RDONLY);
	readed = read(fd,buffer,BUFFER_SIZE);
	head->string = buffer;
	head->next = NULL;
	printf("%s",head->string);
	free(buffer);
	free(head);
	readed = read(fd,buffer,BUFFER_SIZE);
	node = malloc(sizeof(node_t));
	head->next = node;
	node->next = NULL;
	printf("%s",node->string);
	free(buffer);
	free(node);

	close(fd);
}



// *************************************
// LESSON ON YOUTUBE (https://www.youtube.com/watch?v=VOpjAHCee7c&ab_channel=JacobSorber)
// struct node {
// 	int value;
// 	struct node *next;
// };
// typedef struct node node_t;

// *************************************
// THIRD STEP (FULL AUTOMATION)
// node_t *create_new_node(int value)
// {
// 	node_t *result = malloc(sizeof(node_t));
// 	result->value = value;
// 	result->next = NULL;
// 	return result;
// }

// node_t *insert_at_head(node_t **head, node_t *node_to_insert)
// {
// 	node_to_insert->next = *head;
// 	*head = &node_to_insert;
// 	return node_to_insert;
// }

// node_t *insert_after_node(node_t *node_to_insert_after, node_t *newnode)
// {
// 	newnode->next = node_to_insert_after->next;
// 	node_to_insert_after->next = newnode;
// }

// node_t *find_node(node_t *head,int value)
// {
// 	node_t *tmp = head;
// 	while(tmp != NULL)
// 	{
// 		if(tmp->value == value) return tmp;
// 		tmp = tmp->next;
// 	}
// 	return NULL;
// }
// int main()
// {
// 	node_t *head = NULL;
// 	node_t *tmp;

// 	for(int i=0;i<25;i++)
// 	{
// 		tmp = create_new_node(i);
// 		insert_at_head(&head,tmp);
// 	}


// }

// *************************************
// SECOND STEP (IMPLEMENTING FUNCTION CREATE NEW NODE FUNCTION)
// node_t *create_new_node(int value)
// {
// 	node_t *result = malloc(sizeof(node_t));
// 	result->value = value;
// 	result->next = NULL;
// 	return result;
// }
// int main()
// {
// 	node_t *head;
// 	node_t *tmp;

// 	tmp = create_new_node(1);
// 	head = tmp;
// 	tmp = create_new_node(2);
// 	tmp->next=head;
// 	head = tmp;
// 	tmp = create_new_node(3);
// 	tmp->next=head;
// 	head = tmp;
// }

// *************************************
// FIRST STEP
// int main()
// {
// 	node_t n1,n2,n3;
// 	node_t *head;

// 	n1.value = 1;
// 	n2.value = 2;
// 	n3.value = 3;

// 	head = &n1;
// 	n3.next = NULL;
// 	n2.next = &n3;
// 	n1.next = &n2;

// }
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


	close(fd);
}


// struct node {
// 	int value;
// 	struct node *next;
// };
// typedef struct node node_t;

// int main()
// {
// 	node_t n1,n2,n3;
// 	node_t *head;

// 	n1.value = 1;
// 	n2.value = 2;
// 	n3.value = 3;

// 	head = &n3;
// 	n3.next = &n2;
// 	n2.next = &n1;
// 	n1.next = NULL;

// }
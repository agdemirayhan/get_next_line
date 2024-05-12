#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 10

struct				node
{
	char			*string;
	struct node		*next;
};
typedef struct node	node_t;

void	copy_str(node_t *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->string[i])
		{
			if (list->string[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->string[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

void	dealloc(node_t **list, node_t *clean_node, char *buf)
{
	node_t	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->string);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->string[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	char_to_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	return (i);
}

node_t	*find_last_node(node_t *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	append_to_list(node_t **list, char *buffer)
{
	node_t	*new_node;
	node_t	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(node_t));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->string = buffer;
	new_node->next = NULL;
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = strlen(s);
	if (start >= slen)
		return (strdup(""));
	if (len > (slen - start))
		len = slen - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

// void	create_list(node_t **list, int fd)
// {
// 	int		char_read;
// 	char	*buf;

// 	while (!found_newline(*list))
// 	{
// 		buf = malloc(BUFFER_SIZE + 1);
// 		if (NULL == buf)
// 			return ;
// 		char_read = read(fd, buf, BUFFER_SIZE);
// 		if (!char_read)
// 		{
// 			free(buf);
// 			return ;
// 		}
// 		buf[char_read] = '\0';
// 		append_to_list(list, buf);
// 	}
// }

void	print_node_list(node_t *list)
{
	node_t	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%s", tmp->string); // Print the string member of each node
		tmp = tmp->next;
	}
}

int	main(void)
{
	char			*buffer;
	int				readtext;
	int				fd;
	char			*firstpartstr;
	char			*secondpartstr;
	static node_t	*list;
	node_t			*newnode;
	int				charafternewline;
	node_t			*last_node;

	fd = open("test.txt", O_RDONLY);
	readtext = 1;
	while (readtext > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		readtext = read(fd, buffer, BUFFER_SIZE);
		if (!strchr(buffer, '\n'))
		{
			buffer[readtext] = '\0';
			append_to_list(&list, buffer);
		}
		else
		{
			firstpartstr = malloc(sizeof(char) * char_to_newline(buffer));
			firstpartstr = ft_substr(buffer, 0, char_to_newline(buffer));
			append_to_list(&list, firstpartstr);
			// free(list);
			// list = NULL;
			secondpartstr = malloc(sizeof(char) * char_to_newline(buffer));
			secondpartstr = ft_substr(buffer, char_to_newline(buffer),
					strlen(buffer));
			charafternewline = strlen(buffer) - char_to_newline(buffer);
			secondpartstr[charafternewline] = '\0';
			newnode = malloc(sizeof(node_t));
			newnode->string = secondpartstr;
			newnode->next = NULL;
			last_node = find_last_node(list);
			last_node->next = newnode; // Append newnode to the last node
				// free(list);
			
			// dealloc(&list, newnode, buffer);
		}
	}
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
// 	return (result);
// }

// node_t *insert_at_head(node_t **head, node_t *node_to_insert)
// {
// 	node_to_insert->next = *head;
// 	*head = &node_to_insert;
// 	return (node_to_insert);
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
// 		if(tmp->value == value) return (tmp);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
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
// 	return (result);
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
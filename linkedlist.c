#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 300

struct				node
{
	char			*string;
	struct node		*next;
};
typedef struct node	node_t;

int	newlinechecker(node_t *list)
{
	int	i;

	i = 0;
	while (list->string[i] != '\0')
	{
		i++;
		if (list->string[i] == '\n')
			return (1);
	}
	return (0);
}

void	appendtolist(node_t **list, char *buffer)
{
	node_t	*tmp;

	tmp = malloc(sizeof(node_t));
	if (tmp == NULL)
		return ;
	tmp->string = buffer;
	tmp->next = list;
	list = tmp;
}

void	listhandler(node_t **list, int fd)
{
	char	*buffer;
	int		readtext;

	while (!newlinechecker(*list))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return ;
		readtext = read(fd, buffer, BUFFER_SIZE);
		if (!readtext)
		{
			free(buffer);
			return;
		}
		buffer[readtext] = '\0';
		appendtolist(list, buffer);
	}
	return ;
}

char	*get_next_line(int fd)
{
	static node_t	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	listhandler(&list, fd);
	return (next_line);
}

int	main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);

	close(fd);
}
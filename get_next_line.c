/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/19 08:47:39 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct				node
{
	char			*string;
	struct node		*next;
};
typedef struct node	node_t;


int	characters_to_newline(node_t *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->string[i])
		{
			if (list->string[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
}

void	listhandler(int fd, node_t *list)
{
	int		read_block;
	char	*buffer;

	while (!found_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (NULL == buffer)
			return ;
		read_block = read(fd, buffer, BUFFER_SIZE);
		if (!read_block)
		{
			free(buffer);
			return ;
		}
		buffer[read_block] = '\0';
	}
	appendtolist(list,buffer);
}

void	appendtolist(node_t **list, char *buffer)
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

char	*fill(node_t *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

char	*get_next_line(int fd)
{
	static node_t	*list;
	char			*textarr;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	listhandler(fd, &list);
	textarr = fill(list);
	free(buffer);
	return (textarr);
}

// int main(void) {
//     int fd;
//     // Open the file
//     fd = open("test.txt", O_RDONLY);
//     // Display the read data
//     get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     close(fd);
//     return (0);
// }

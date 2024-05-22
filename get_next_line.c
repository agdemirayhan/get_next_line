/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/22 22:03:39 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Werror -Wextra *.c *.h && ./a.out | cat -e

void	next_line_organizer(t_node **list)
{
	char	*buffer;
	t_node	*newline_node;
	t_node	*last_node;
	int		i;
	int		j;

	buffer = malloc(BUFFER_SIZE + 1);
	newline_node = malloc(sizeof(t_node));
	if (buffer == NULL || newline_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->string[i] && last_node->string[i] != '\n')
		i++;
	buffer[j] = '\0';
	while (last_node->string[i] && last_node->string[i++])
		buffer[j++] = last_node->string[i];
	buffer[j] = '\0';
	newline_node->string = buffer;
	newline_node->next = NULL;
	delete_list(list);
	if (newline_node->string[0])
		*list = newline_node;
	else
	{
		free(newline_node);
		free(buffer);
	}
}

void	appendtolist(t_node **list, char *buffer)
{
	t_node	*new_node;
	t_node	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->string = buffer;
	new_node->next = NULL;
}

void	listhandler(int fd, t_node **list)
{
	int		read_block;
	char	*buffer;

	while (!newline_check(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		read_block = read(fd, buffer, BUFFER_SIZE);
		if (!read_block)
		{
			free(buffer);
			return ;
		}
		buffer[read_block] = '\0';
		appendtolist(list, buffer);
	}
}

char	*fill(t_node *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = characters_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

char	*get_next_line(int fd)
{
	static t_node	*list;
	char			*textarr;
	t_node			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &textarr, 0) < 0)
	{
		while (list)
		{
			temp = list;
			list = list->next;
			free(temp->string);
			free(temp);
		}
		return (NULL);
	}
	listhandler(fd, &list);
	if (list == NULL)
		return (NULL);
	textarr = fill(list);
	next_line_organizer(&list);
	return (textarr);
}

// #include <time.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		tic;
// 	int		toc;

// 	fd = open("lines_around_10.txt", O_RDONLY);
// 	tic = clock();
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	toc = clock();
// 	printf("Elapsed time: %f\n", (double)(toc - tic) / CLOCKS_PER_SEC);
// 	close(fd);
// 	return (0);
// }

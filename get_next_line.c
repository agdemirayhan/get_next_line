/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/23 22:44:20 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Werror -Wextra *.c *.h && ./a.out | cat -e

void	next_line_organizer(t_nod **list)
{
	char	*buffer;
	t_nod	*newline_node;
	t_nod	*last_nod;
	int		i;
	int		j;

	buffer = malloc(BUFFER_SIZE + 1);
	newline_node = malloc(sizeof(t_nod));
	if (buffer == NULL || newline_node == NULL)
	{
		free(buffer);       // Free buffer if malloc fails
		free(newline_node); // Free newline_node if malloc fails
		return ;
	}
	last_nod = find_last_nod(*list);
	i = 0;
	j = 0;
	while (last_nod->string[i] && last_nod->string[i] != '\n')
		i++;
	buffer[j] = '\0';
	while (last_nod->string[i] && last_nod->string[i++])
		buffer[j++] = last_nod->string[i];
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

void	appendtolist(t_nod **list, char *buffer)
{
	t_nod	*new_node;
	t_nod	*last_nod;

	last_nod = find_last_nod(*list);
	new_node = malloc(sizeof(t_nod));
	if (new_node == NULL)
	{
		free(buffer);
		return ;
	}
	last_nod = find_last_nod(*list);
	new_node->string = buffer;
	new_node->next = NULL;
	if (last_nod == NULL)
		*list = new_node;
	else
		last_nod->next = new_node;
}

void	listhandler(int fd, t_nod **list)
{
	int		read_block;
	char	*buffer;

	while (1)
	{
		if (newline_check(*list))
			return ;
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		read_block = read(fd, buffer, BUFFER_SIZE);
		if (read_block <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_block] = '\0';
		appendtolist(list, buffer);
	}
}

char	*fill(t_nod *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = characters_to_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

char	*get_next_line(int fd)
{
	static t_nod	*list;
	char			*textarr;
	t_nod			*temp;

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
	if (textarr == NULL)
		return (NULL);
	next_line_organizer(&list);`
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/18 09:19:37 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
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
		append(list, buffer);
	}
}

char	*ft_fill(int fd, char *left_from_line, char *buffer)
{
	ssize_t	readblock;
	char	*temp;
	int		i;

	readblock = read(fd, buffer, BUFFER_SIZE);
	if (readblock < 1)
	{
		return (NULL);
	}
	if (!left_from_line)
		left_from_line = ft_strdup("");
	temp = left_from_line;
	left_from_line = ft_strjoin(temp, buffer);
	free(temp);
	temp = NULL;
	if (strchr(left_from_line, '\n'))
	{
		i = characters_to_newline(left_from_line);
		left_from_line[i + 1] = '\0'; // Ensure null termination
		return (left_from_line);
	}
	else
	{
		// Fix recursion by returning the result of ft_fill
		return (ft_fill(fd, left_from_line, buffer));
	}
}

char	*get_next_line(int fd)
{
	static node_t	*list;
	char			*textarr;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	listhandler(fd, &list);
	// textarr = ft_fill(fd, left_from_line, buffer);
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

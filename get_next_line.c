/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/28 17:09:30 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	buffer_size;
	size_t	used;
	int		c;
	char	*temp;

	buffer = (char *)malloc((buffer_size + 1) * sizeof(char));
		// Allocate memory for the buffer
	if (buffer == NULL)
		return (NULL); // allocation error
	used = 0;
	while (((read(fd, &c, 2)) > 0) && used < buffer_size)
	{
		if (c == '\n')
			break ;
		if (used == buffer_size) // Check if the buffer is full
		{
			// Resize the buffer
			temp = (char *)realloc(buffer, (buffer_size * 2 + 1)
					* sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return (NULL); // allocation error
			}
			buffer = temp;
			buffer_size *= 2; // Update buffer_size
		}
		buffer[used++] = c;
	}
	if (c == -1 && used == 0)
	{
		free(buffer);
		return (NULL); // error or EOF
	}
	buffer[used] = '\0';
	return (buffer);
}

int	main(void)
{
	// Open your file here (replace with your file opening code)
	int fd = open("test.txt", O_RDONLY); // Assuming read-only access

	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	char *line = get_next_line(fd);
	if (line == NULL)
	{
		perror("read_line");
		close(fd);
		return (1);
	}

	// Process the line here using `line`
	printf("Read line: %s", line);

	// Don't forget to free the memory after use
	free(line);

	close(fd); // Close the file descriptor

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/01 12:23:02 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill(int fd, char *lines_read, char *buffer, char *line)
{
	if(ft_strchr(buffer, '\n'))
		return printf("ABORT");
		
	
	ft_memcpy(line, buffer, lines_read);
	write(STDOUT_FILENO, line, lines_read);

	return line;
}

char	*get_next_line(int fd)
{
	char	*lines_read;
	char	*line;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	lines_read = read(fd, buffer, BUFFER_SIZE);
	if (lines_read == -1)
	{
		return (NULL);
	}
	line = (char *)malloc(lines_read + 1);
	if (line == NULL)
	{
		return (NULL);
	}
	line = ft_fill(fd, lines_read, buffer, line);
	return (line);
}

int	main(void)
{
	int fd;

	// Open the file
	fd = open("test.txt", O_RDONLY);

	// Display the read data
	get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);

	// Close the file
	close(fd);

	return (0);
}
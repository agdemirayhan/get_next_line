/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/01 10:32:06 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char	*line;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1) * sizeof(char);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		return (NULL);
	}
	line = (char *)malloc(bytes_read + 1);
	if (line == NULL)
	{
		return (NULL);
	}
	line = ft_fill(fd, bytes_read, buffer);
	line[bytes_read] = '\0';
	return (line);
}

char	*ft_fill(int fd, char *line, char *buffer)
{
	ft_memcpy(line, buffer, bytes_read);
	write(STDOUT_FILENO, line, bytes_read);
}
// int	main(void)
// {
// 	int fd;

// 	// Open the file
// 	fd = open("test.txt", O_RDONLY);

// 	// Display the read data
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);

// 	// Close the file
// 	close(fd);

// 	return (0);
// }
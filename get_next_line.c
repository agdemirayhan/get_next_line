/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/01 09:39:23 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	static char	*line;

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
	ft_memcpy(line, buffer, bytes_read);
	line[bytes_read] = '\0';
	write(STDOUT_FILENO, line, bytes_read);
	return (line);
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
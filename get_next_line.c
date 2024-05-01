/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/01 19:24:07 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int characters_to_newline(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    return i;
}

char *ft_fill(size_t lines_read, char *buffer, char *line)
{
    int i = characters_to_newline(buffer);
    if (ft_strchr(buffer, '\n'))
       ft_strljoin(line, buffer, i);
    else
        ft_strljoin(line, buffer, lines_read);
		// printf("line:%s",line);
    line[i] = '\0'; // Null-terminate the line
    write(STDOUT_FILENO, line, lines_read);
    return line;
}

char *get_next_line(int fd)
{
    char *line;
    char buffer[BUFFER_SIZE + 1];
    ssize_t lines_read = read(fd, buffer, BUFFER_SIZE);
    if (lines_read <= 0 || fd<0)
    {
        return NULL; // Error or end-of-file
    }
    line = (char *)malloc(lines_read + 1);
    if (line == NULL)
    {
        return NULL; // Memory allocation failed
    }
    line = ft_fill(lines_read, buffer, line);
    return line;
}

int main(void)
{
    int fd;
    // Open the file
    fd = open("test.txt", O_RDONLY);
    // Display the read data
    get_next_line(fd);
    // get_next_line(fd);
    // get_next_line(fd);
    close(fd);
    return 0;
}
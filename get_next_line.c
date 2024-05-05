/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/05 17:36:07 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int characters_to_newline(char *buffer) {
    int i = 0;
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    return i;
}

char *ft_fill(int fd, char *left_from_line, char *buffer) {
    ssize_t readblock;
    char *temp;
    int i;

    readblock = read(fd, buffer, BUFFER_SIZE);
    if (readblock < 1) {
        return NULL;
    }

    if (!left_from_line)
        left_from_line = ft_strdup("");
    temp = left_from_line;
    left_from_line = ft_strjoin(temp, buffer);
    free(temp);
    temp = NULL;

    if (strchr(left_from_line, '\n')) {
        i = characters_to_newline(left_from_line);
        left_from_line[i + 1] = '\0'; // Ensure null termination
        return left_from_line;
    } else {
        // Fix recursion by returning the result of ft_fill
        return ft_fill(fd, left_from_line, buffer);
    }
}

char *get_next_line(int fd) {
    static char *left_from_line;
    char *buffer;
    char *textarr;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0) {
        free(buffer);
        return NULL;
    }

    textarr = ft_fill(fd, left_from_line, buffer);
    free(buffer);
    return textarr;
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
//     return 0;
// }

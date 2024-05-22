/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:59:34 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/22 22:02:46 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct					s_node
{
	char				*string;
	struct s_node		*next;
};
typedef struct s_node	t_node;

char					*get_next_line(int fd);
void					delete_list(t_node **list);
int						characters_to_newline(t_node *list);
t_node					*find_last_node(t_node *list);
int						newline_check(t_node *list);
void					copy_str(t_node *list, char *str);

#endif
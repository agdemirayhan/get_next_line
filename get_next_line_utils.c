/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:10:05 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/19 18:47:40 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	delete_list(node_t **list)
{
	node_t	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->string);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

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
		while (list->string[i])
		{
			if (list->string[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

node_t	*find_last_node(node_t *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	newline_check(node_t *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->string[i] && i < BUFFER_SIZE )
		{
			if (list->string[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	copy_str(node_t *list, char *str)
{
	int	i;
	int	j;

	if (NULL == list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->string[i])
		{
			if (list->string[i] == '\n')
			{
				str[j] = '\n';
				j++;
				str[j] = '\0';
				return ;
			}
			str[j++] = list->string[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

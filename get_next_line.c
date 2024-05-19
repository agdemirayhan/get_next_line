/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:09:37 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/19 16:52:32 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 void	 delete_list(node_t **list)
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


    void  next_line_organizer(node_t **list)
    {
        char *buffer;
        node_t *newline_node;
        node_t *last_node;
        int i;
        int j;

        buffer = malloc(sizeof(char));

        last_node = find_last_node(*list);
        newline_node = malloc(sizeof(node_t));
 
        i =0;
        j =0;
        while (last_node->string[i] != '\n' && last_node->string[i] != '\0')
            i++;
        while(last_node->string[++i]!='\0')
        {
            buffer[j] = last_node->string[i];
            j++;
        }
        buffer[j] = '\0';
        newline_node->string = buffer;
        newline_node->next=NULL;
        delete_list(list);
        
        // printf("newline_node:%s\n",newline_node->string);
    
    }



void print_list(node_t *head)
{
  node_t *current;
  current = head;
  int i = 0;
  while (current != NULL)
  {
    printf("%s\n", current->string);
    i++;
    current = current->next;
  }
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
	return len;
}

void	appendtolist(node_t **list, char *buffer)
{
	node_t	*new_node;
	node_t	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(node_t));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->string = buffer;
	new_node->next = NULL;
}

void	listhandler(int fd, node_t **list)
{
	int		read_block;
	char	*buffer;

	while (!newline_check(*list))
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
	appendtolist(list,buffer);
	}
}

char	*fill(node_t *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = characters_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

char	*get_next_line(int fd)
{
	static node_t	*list;
	char			*textarr;
    node_t *temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &textarr, 0) < 0)
	{
		if (list)
		{
			while (list)
			{
				node_t *temp = list;
				list = list->next;
				free(temp->string);
				free(temp);
			}
		}
		return (NULL);
	}
	listhandler(fd, &list);
    if (list == NULL)
		return (NULL);
	// printf("first\n");
	// print_list(list);
	textarr = fill(list);
    next_line_organizer(&list);
	// printf("second\n");
	// printf("%s",textarr);
    // delete_list(list);
	return (textarr);
}

int main(void) {
    int fd;
	char *line;
    fd = open("test.txt", O_RDONLY);
   line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
    // get_next_line(fd);
    // get_next_line(fd);
    close(fd);
    return (0);
}


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct				node
{
	char			*string;
	struct node		*next;
};
typedef struct node	node_t;

char	*get_next_line(int fd);
void				delete_list(node_t **list);
int					characters_to_newline(node_t *list);
node_t				*find_last_node(node_t *list);
int					newline_check(node_t *list);
void				copy_str(node_t *list, char *str);

#endif
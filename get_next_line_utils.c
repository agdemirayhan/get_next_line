/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:10:05 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/01 12:22:13 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *destination;
	const char *source;
	size_t i;

	if (dst == NULL && src == NULL)
		return (NULL);
	destination = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;
	int		j;

	a = (char)c;
	i = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == a && s[i])
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == a)
		return ((char *)(s + i));
	return (NULL);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:10:05 by aagdemir          #+#    #+#             */
/*   Updated: 2024/05/05 19:13:19 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		s1len;

	s1len = ft_strlen(s1);
	s2 = (char *)malloc((s1len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, s1len);
	s2[s1len] = '\0';
	return (s2);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;
	size_t	totallen;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totallen = s1len + s2len;
	str = (char *)malloc((totallen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len);
	str[totallen] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	size_t		i;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		len = slen - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:23:11 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/28 11:37:08 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

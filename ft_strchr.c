/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:23:11 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 18:59:18 by aagdemir         ###   ########.fr       */
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

// #include <string.h>

// int	main(void)
// {
// 	char	*src;
// 	char	*d1;
// 	char	*d2;

// 	src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
// 	d1 = strchr(src, '\0');
// 	d2 = ft_strchr(src, '\0');
// 	printf("d1:%s\n", d1);
// 	printf("d2:%s\n", d2);
// }

// int	main(void)
// {
// 	char *s1 = "\0";
// 	char *d1 = strchr(s1, 'a');
// 	char *d2 = ft_strchr(s1, 'a');
// 	printf("d1:%s\n", d1);
// 	printf("d2:%s\n", d2);
// }

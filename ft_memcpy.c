/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:18:49 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 18:56:56 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char src[19] = "abcdef";

// 	char *target = src;

// 	// ft_memcpy(target+3,target,5);
// 	// printf("from ft_memcpy  : %s\n", target);

// 	// strncpy(target+3,target,5);
// 	// printf("from strncpy : %s\n", target);

// 	memmove(target + 3, target, 5);
// 	printf("from memmove 	: %s\n", target);

// 	memcpy(target + 3, target, 5);
// 	printf("from memcpy  	: %s\n", target);
// }
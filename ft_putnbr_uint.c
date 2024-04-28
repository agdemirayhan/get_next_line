/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:51:42 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 19:03:38 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uint(unsigned long d)
{
	int		len;
	char	*base;
	int		check;

	len = 0;
	base = "0123456789";
	if (d > (ft_strlen(base) - 1))
	{
		check = ft_putnbr_uint(d / ft_strlen(base));
		if (check == -1)
			return (check);
		len += check;
	}
	check = ft_putchar(*(base + (d % ft_strlen(base))));
	if (check == -1)
		return (check);
	len += check;
	return (len);
}

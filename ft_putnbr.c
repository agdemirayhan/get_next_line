/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:50:14 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 19:03:31 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int d)
{
	char	*s;
	int		len;

	if (d == 0)
		return (ft_putchar('0'));
	s = ft_itoa(d);
	len = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (len);
}

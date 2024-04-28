/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:51:02 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 19:03:24 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexvalue(unsigned int d, char format)
{
	int		len;
	char	*hexvalues;
	int		check;

	hexvalues = "0123456789abcdef";
	if (format == 'X')
		hexvalues = "0123456789ABCDEF";
	if (d < 16)
		return (ft_putchar(hexvalues[d]));
	else
	{
		check = ft_puthexvalue(d / 16, format);
		if (check == -1)
			return (check);
		len = check;
		return (len + ft_puthexvalue(d % 16, format));
	}
	return (len);
}

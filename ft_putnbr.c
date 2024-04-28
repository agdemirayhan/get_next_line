/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:50:14 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/28 14:00:10 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putnbr(int d)
// {
// 	char	*s;
// 	int		len;

// 	if (d == 0)
// 		return (ft_putchar('0'));
// 	s = ft_itoa(d);
// 	len = ft_strlen(s);
// 	ft_putstr(s);
// 	free(s);
// 	return (len);
// }

int	ft_digitcounter(int n)
{
	int	temp;
	int	digit;

	digit = 0;
	temp = n;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		temp = -temp;
		digit++;
	}
	while (temp != 0)
	{
		digit++;
		temp /= 10;
	}
	if (n == 0)
		digit = 1;
	return (digit);
}

int	ft_putnbr(int n)
{
	int	digitcounter;
	int	check;

	digitcounter = ft_digitcounter(n);
	if (n == INT_MIN)
	{
		if(ft_putstr("-2147483648") == -1)
			return -1;
		return digitcounter;
	}
	if (n < 0)
	{
		check = ft_putchar('-');
		if (check == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if(ft_putnbr(n / 10) == -1)
			return -1;
		check = ft_putchar(n % 10 + '0');
		if (check == -1)
			return (-1);
	}
	else
	{
		check = ft_putchar(n + '0');
		if (check == -1)
			return (-1);
	}
	return (digitcounter);
}

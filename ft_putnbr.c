/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:50:14 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/28 16:54:35 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	digitcounter = ft_digitcounter(n);
	if (n == INT_MIN)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (digitcounter);
	}
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if ((ft_putnbr(n / 10) == -1) || (ft_putchar(n % 10 + '0') == -1))
			return (-1);
	}
	else if (ft_putchar(n + '0') == -1)
		return (-1);
	return (digitcounter);
}

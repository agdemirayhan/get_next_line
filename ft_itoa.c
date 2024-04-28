/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:08:01 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/28 12:19:18 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digitcounter(int n)
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

char	*reverser(char *str, int i)
{
	int	temp;
	int	start;
	int	end;

	if (str[0] == '-')
		start = 1;
	else
		start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*minhandler(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, "-2147483648", 11);
	str[11] = '\0';
	return (str);
}

char	*stringhandler(char *str, int n)
{
	int	i;
	int	digit;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	else if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n != 0)
	{
		digit = n % 10;
		str[i++] = '0' + digit;
		n /= 10;
	}
	str[i] = '\0';
	reverser(str, i);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	if (n == INT_MIN)
		return (minhandler());
	digits = digitcounter(n);
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	stringhandler(str, n);
	return (str);
}

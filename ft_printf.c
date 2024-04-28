/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:42:34 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/28 11:05:13 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addresshandler_loop(void *p, int zerojumper, int printed_chars,
		uintptr_t ptr)
{
	int	i;

	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		if (!(hex_digit((ptr >> i) & 0xf) == '0' && zerojumper == 1))
		{
			zerojumper = 0;
			if (ft_putchar(hex_digit((ptr >> i) & 0xf)) == -1)
				return (-1);
			printed_chars++;
		}
		i -= 4;
	}
	return (printed_chars);
}

int	ft_addresshandler(void *p)
{
	int			printed_chars;
	int			zerojumper;
	uintptr_t	ptr;

	ptr = (uintptr_t)p;
	printed_chars = 2;
	zerojumper = 1;
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ptr == 0)
		printed_chars += ft_putchar('0');
	else
		printed_chars = ft_addresshandler_loop(p, zerojumper, printed_chars,
				ptr);
	return (printed_chars);
}

static int	ft_format(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (format == 'X' || format == 'x')
		return (ft_puthexvalue(va_arg(args, unsigned int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_addresshandler(ptr));
		return (ft_putstr("0x0"));
	}
	else if (format == 'u')
		return (ft_putnbr_uint(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;
	int		check;

	i = 0;
	printed_chars = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_strchr("cspdiuxX%", *(str + i + 1)))
			check = ft_format(args, *(str + i++ + 1));
		else
			check = ft_putchar(*(str + i));
		printed_chars += check;
		if (check == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (printed_chars);
}

// int	main(void)
// {
// 	ft_printf("%d", -10);
// 		//  printf("%u\n", UINT32_MAX);

// }
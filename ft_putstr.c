/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:49:50 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 19:03:41 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	if (write(1, s, ft_strlen(s)) == -1)
		return (-1);
	else
		return (ft_strlen(s));
}

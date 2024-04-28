/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagdemir <aagdemir@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:18:53 by aagdemir          #+#    #+#             */
/*   Updated: 2024/04/20 19:19:15 by aagdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putstr(char const *s);
int		ft_putnbr(int d);
int		ft_putnbr_uint(unsigned long d);
int		ft_puthexvalue(unsigned int d, char format);
int		ft_putchar(char c);
char	*ft_itoa(int n);
char	hex_digit(int v);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);

#endif
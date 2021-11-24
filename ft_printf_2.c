/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:16:49 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/24 13:31:35 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/* this function for %d */
int	ft_print_nbr(int n, int count)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		count = ft_print_char('-', count);
		nbr = -n;
	}
	if (nbr >= 10)
		count = ft_print_nbr(nbr / 10, count);
	count = ft_print_char((nbr % 10 + '0'), count);
	return (count);
}

/* this function is integrated within all other functions */
int	ft_print_char(int c, int count)
{
	write (1, &c, 1);
	count++;
	return (count);
}

/* this function is for %x */
int	ft_hexa_low(unsigned int n, int count)
{
	unsigned long long	nbr;

	nbr = n % 16;
	if (n >= 16)
		count = ft_hexa_up(n / 16, count);
	if (nbr == 10)
		count = ft_print_char('a', count);
	else if (nbr == 11)
		count = ft_print_char('b', count);
	else if (nbr == 12)
		count = ft_print_char('c', count);
	else if (nbr == 13)
		count = ft_print_char('d', count);
	else if (nbr == 14)
		count = ft_print_char('e', count);
	else if (nbr == 15)
		count = ft_print_char('f', count);
	else
		count = ft_print_char(nbr + '0', count);
	return (count);
}

/* these two function for the %s argument */
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_print_str(char *str, int count)
{
	if (str)
	{
		write (1, str, ft_strlen(str));
		count += ft_strlen(str);
	}
	else
		count = ft_print_str("(null)", count);
	return (count);
}

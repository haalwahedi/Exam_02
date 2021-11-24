/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:06:29 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/24 13:55:08 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

/* for the exam we will cover the following arguments, d, s, & x
* %s print a string of characters
* %d print a decimal (base 10) number.
* %x print a number in hexadecimal (base 16), with lowercase. */

int	ft_args(char c, va_list ap, int count)
{		
	else if (c == 's')
		count = ft_print_str(va_arg(ap, char *), count);
	else if (c == 'd')
		count = ft_print_nbr(va_arg(ap, int), count);
	else if (c == 'x')
		count = ft_hexa_low(va_arg(ap, unsigned int), count);
	return (count);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		ct;
	int		i;

	i = 0;
	va_start(args, ptr);
	ct = 0;
	while (ptr[i])
	{
		if (ptr[i] != '%')
		{
			ct = ft_print_char(ptr[i], ct);
		}
		else if (ptr[i] == '%')
		{
			ct = ft_args(ptr[++i], args, ct);
		}
		i++;
	}
	va_end(args);
	return (ct);
}

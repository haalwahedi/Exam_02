/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:07:02 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/28 14:15:59 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_chars(char *s1, char *s2)
{
	int tab[256] = {0};
	int	i  = 0;

	while (s2[i])
		tab[(int)s2[i++]] = 1;
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			tab[(int)s1[i]] = 2;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		print_chars(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

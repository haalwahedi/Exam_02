/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:07:18 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/28 14:05:12 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	s[256] = {0};
	int	i, j;

	i = 0;
	j = 1;
	if (ac == 3)
	{
		while(j < 3)
		{
			while (av[j][i])
					s[(int)av[j][i++]] = 1;
			i = 0;
			j++;
		}
		j = 1;
		while (j < 3)
		{
			while (av[j][i])
			{
				if (s[(int)av[j][i]] == 1)
				{
					write(1, &av[j][i], 1);
					s[(int)av[j][i]] = 2;
				}
				i++;
			}
			i = 0;
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

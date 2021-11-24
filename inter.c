/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:07:02 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/24 13:54:32 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	ft_find(char *str, int chr2find)
{
	while (*str)
	{
		if (*str++ == chr2find)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (ft_find(argv[2], argv[1][i]) != 0)
			{
				j = i - 1;
				while (j >= -1)
				{
					if (argv[1][i] == argv[1][j])
						break ;
					else if (j == -1)
						write(1, &argv[1][i], 1);
					j--;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

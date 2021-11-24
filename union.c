/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:07:18 by halwahed          #+#    #+#             */
/*   Updated: 2021/11/24 13:53:59 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	*ft_strjoin_no_malloc(char *s1, char *s2)
{
	char	*str_sum;
	int		i;

	i = 0;
	str_sum = s1;
	while (*s1 != '\0')
		str_sum[i++] = *s1++;
	while (*s2 != '\0')
		str_sum[i++] = *s2++;
	str_sum[i] = '\0';
	return (str_sum);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str_sum;

	i = 0;
	if (argc == 3)
	{
		str_sum = ft_strjoin_no_malloc(argv[1], argv[2]);
		while (str_sum[i])
		{
			j = i - 1;
			while (j >= -1)
			{
				if (str_sum[j] == str_sum[i])
					break ;
				else if (j == -1)
					write(1, &str_sum[i], 1);
				j--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

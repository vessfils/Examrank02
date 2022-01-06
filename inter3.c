/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:25:29 by vess              #+#    #+#             */
/*   Updated: 2022/01/05 14:40:53 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main (int ac, char **av)
{
	int	i;
	int	j;
	int	used[256] = {0};

	if (ac == 3)
	{
		i = 2;
		while (i > 0)
		{
				j = 0;
			while (av[i][j])
			{
				if (i == 2 && used[(unsigned char)av[i][j]] == 0)
					used[(unsigned char)av[i][j]] = 1;
				if (i == 1 && used[(unsigned char)av[i][j]] == 1)
				{
					write(1, &av[i][j], 1);
					used[(unsigned char)av[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

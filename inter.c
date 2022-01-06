/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:26:50 by vess              #+#    #+#             */
/*   Updated: 2021/12/19 23:22:13 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int	main(int ac, char **av)
{
	int	used[255];
	int	i, j;

	if (ac == 3)
	{
		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (used[(unsigned char)av[2][j]] == 0 && av[1][i] == av[2][j])
				{

					write(1, &av[1][i], 1);
					used[(unsigned char)av[1][i]] = 1;
					break;
				}
			
				j++;
			}


			i++;
		}
		
	}
	write(1, "\n", 1);
	return (0);
}

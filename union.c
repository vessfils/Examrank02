/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:45:01 by vess              #+#    #+#             */
/*   Updated: 2022/01/05 14:54:24 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	int used[256] = {0};

	if (ac == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if ( used[(unsigned char )av[i][j]] == 0)
				{
					write(1, &av[i][j], 1);
					used[(unsigned char )av[i][j]] = 1;
				}
				j++;
			}
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}

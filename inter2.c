/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:54:40 by vess              #+#    #+#             */
/*   Updated: 2021/12/21 22:59:52 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int checkdouble (char *str, char c , int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

   int main (int ac, char**av)
   {
   int i;
   int j;

   i = 0;
   if (ac == 3)
   {
   while (av[1][i])
   {
   j = 0;
   while (av[2][j])
   {
   if (av[1][i] == av[2][j] && checkdouble(av[1], av[1][i], i))
   {
   write (1, &av[1][i], 1);
   break;
   }	
   j++;
   }
   i++;
   }
   }
   write (1, "\n", 1);
   return (0);
   }


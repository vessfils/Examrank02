/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:26:31 by vess              #+#    #+#             */
/*   Updated: 2022/01/06 11:52:01 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar (char c)
{
	write(1, &c, 1);
}

int ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_printstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_nbrlen (int nbr)
{
	int i;

	i = 0;

	if (nbr <= 0)
		i++;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

void ft_putnbr(int nb)
{
	long int	nbr;

	nbr = nb;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nbr; 
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int ft_printnumber(int nb)
{
	ft_putnbr(nb);
	return (ft_nbrlen(nb));
}

int ft_hexalen (unsigned int nb)
{
	int i;

	i = 0;
	while (nb)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

void ft_puthexa(unsigned int nb)
{
	char *base;

	base = "0123456789abcd";
	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
		ft_puthexa(nb % 16);
	}
	else
		ft_putchar(base[nb]);
}

int ft_printhex (unsigned int nb)
{
	if (nb == 0)
		return (write (1, "0", 1));
	else
		ft_puthexa(nb);
	return (ft_hexalen(nb));
}

int ft_format(va_list args, const char flag)
{
	int size;

	size = 0;
	if (flag == 'c')
		size += ft_printchar(va_arg(args, int));
	else if (flag == 's')
		size += ft_printstr(va_arg(args, char *));
	else if (flag == 'd')
		size += ft_printnumber(va_arg(args, int));
	else if (flag == 'x')
		size += ft_printhex(va_arg(args, unsigned int));
	return (size);
}

int ft_printf(const char *str, ... )
{
	va_list args;
	int	i;
	int	size;

	size = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = size + ft_format(args, str[i + 1]);
			i++;
		}
		else
			size = size + ft_printchar(str[i]);
	i++;
	}
	va_end(args);
	return (size);
}

int main ()
{
	char a = 'c';

	char *str = "Hello";
	char *str1 = NULL;
	int nb = 42;
	int max = 2147483647;
	int min = -2147483648;
	
	ft_printf("%c\n", a);
	ft_printf("LOOOOOOOOOOOOL\n");
	ft_printf("%s\n", str);
	ft_printf("%s\n", str1);
	ft_printf("%d\n", nb);
	ft_printf("%d\n", max);
	ft_printf("%d\n", min);
	ft_printf("%x\n", nb);

	return (0);
}



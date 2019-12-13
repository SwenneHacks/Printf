/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 13:50:57 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/13 15:26:54 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n % 10 + '0');
	return ;
}

void	ft_putnbr_base(unsigned long n, int base, char c)
{
	if (n > 15)
	{
		ft_putnbr_base(n / base, base, c);
		ft_putnbr_base(n % base, base, c);
	}
	else if (n > 9 && c == 'x')
		ft_putchar(n + 87);
	else if (n > 9 && c == 'X')
		ft_putchar(n + 55);
	else
		ft_putchar(n % base + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

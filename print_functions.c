/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:27:17 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:37:36 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_return++;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

int		ft_putchar_while(char c, int i)
{
	if (i < 0)
		return (0);
	while (i)
	{
		ft_putchar(c);
		i--;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	long	res;
	int		nav;
	int		sign;

	nav = 0;
	sign = 1;
	res = 0;
	while (str[nav] == 32 || (str[nav] >= 9 && str[nav] <= 13 && str[nav]))
		nav++;
	if (str[nav] == '-')
	{
		sign = -1;
		nav++;
	}
	else if (str[nav] == '+')
		nav++;
	while (str[nav] >= '0' && str[nav] <= '9')
	{
		if (res < 0 && sign < 0)
			return (0);
		else if (res < 0 && sign > 0)
			return (-1);
		res = res * 10 + str[nav++] - '0';
	}
	return (res * sign);
}

int		ft_isdigit_signed(int c)
{
	if ((c <= 57 && c >= 48) || (c == '-') || (c == '+'))
		return (1);
	else
		return (0);
}

int		ft_calcnbr(int nbr, unsigned long binf, unsigned long bsup)
{
	int	i;

	i = 1;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		i++;
		nbr = nbr * -1;
	}
	if (0 <= nbr && nbr <= 9)
		return (i);
	while (1)
	{
		if (binf <= (unsigned long)nbr && (unsigned long)nbr < bsup)
			return (i);
		else
		{
			binf = bsup;
			bsup *= 10;
			i++;
		}
	}
	return (i);
}

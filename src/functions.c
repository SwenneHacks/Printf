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

#include "../printf.h"

void	init_globalv(void)
{
	g_return = 0;
	g_flag = -1;
	g_width = 0;
	g_period = 0;
	g_precision = 0;
}

int		ft_sign(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

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

int		ft_putlen(char c, int len)
{
	if (len < 0)
		return (0);
	while (len)
	{
		ft_putchar(c);
		len--;
	}
	return (0);
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

void	ft_putocta(unsigned long n)
{
	if (n > 7)
	{
		ft_putocta(n / 8);
		ft_putocta(n % 8);
	}
	else
		ft_putchar(n % 8 + '0');
}

void	ft_puthexa(unsigned long n, char c)
{
	if (n > 15)
	{
		ft_puthexa(n / 16, c);
		ft_puthexa(n % 16, c);
	}
	else if (n > 9 && c == 'x')
		ft_putchar(n + 87);
	else if (n > 9 && c == 'X')
		ft_putchar(n + 55);
	else
		ft_putchar(n % 16 + '0');
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

int	ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result < 0 && sign == -1)
			return (0);
		if (result < 0 && sign == 1)
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int		ft_isdigit_signed(int c)
{
	return((c <= 57 && c >= 48) || (c == '-') || (c == '+'));
}

size_t	ft_lenbase(long long nbr, int base)
{
	size_t len;

	len = 1;
	if (nbr < 0)
		len++;
	if (base == 1)
	{
		if (nbr < 0)
			nbr = nbr * -1;
		return ((size_t)nbr + len);
	}
	while (nbr / base != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

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

int	ft_maxof(int v1, int v2)
{
	return ((v1 < v2) ? (v2) : (v1)); 
}

void	pt_putchar(t_info *node, char c)
{
	write(1, &c, 1);
	node->ret_value++;
}

int		pt_putsign(t_info *node, int nbr)
{
	if (nbr >= 0)
	{
		if (node->sign == PLUS)
			pt_putchar(node, '+');
		else if (node->sign == SPACE)
			pt_putchar(node, ' ');
	}
	else
	{
		pt_putchar(node, '-');
		nbr = nbr * -1;
	}
	return (nbr);
}

void	pt_putstr(t_info *node, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		pt_putchar(node, str[i]);
		i++;
	}
}

int		pt_putlen(t_info *node, char c, int len)
{
	if (len < 0)
		return (0);
	while (len)
	{
		pt_putchar(node, c);
		len--;
	}
	return (0);
}

void	pt_putnbr(t_info *node, unsigned long n)
{
	unsigned long nb;

	nb = n;
	if (n < 0)
	{
		pt_putchar(node, '-');
		nb = -n;
	}
	if (nb <= 9)
	{
		pt_putchar(node, nb + 48);
	}
	if (nb > 9)
	{
		pt_putnbr(node, nb / 10);
		pt_putchar(node, nb % 10 + 48);
	}
}

void	pt_putocta(t_info *node, unsigned long n)
{
	if (n > 7)
	{
		pt_putocta(node, n / 8);
		pt_putocta(node, n % 8);
	}
	else
		pt_putchar(node, n % 8 + '0');
}

void	pt_puthexa(t_info *node, unsigned long n, char c)
{
	if (n > 15)
	{
		pt_puthexa(node, n / 16, c);
		pt_puthexa(node, n % 16, c);
	}
	else if (n > 9 && c == 'x')
		pt_putchar(node, n + 87);
	else if (n > 9 && c == 'X')
		pt_putchar(node, n + 55);
	else
		pt_putchar(node, n % 16 + '0');
}

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				i;
	int				sign;

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
		if (result >= 9223372036854775807 && sign == -1)
			return (0);
		if (result >= 9223372036854775807 && sign == 1)
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

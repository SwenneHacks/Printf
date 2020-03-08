/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 13:50:57 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 19:41:03 by swofferh      ########   odam.nl         */
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

void	ft_putnbr_octa(unsigned long n)
{
	if (n > 7)
	{
		ft_putnbr_octa(n / 8);
		ft_putnbr_octa(n % 8);
	}
	else
		ft_putchar(n % 8 + '0');
}

void	ft_putnbr_hexa(unsigned long n, char c)
{
	if (n > 15)
	{
		ft_putnbr_hexa(n / 16, c);
		ft_putnbr_hexa(n % 16, c);
	}
	else if (n > 9 && c == 'x')
		ft_putchar(n + 87);
	else if (n > 9 && c == 'X')
		ft_putchar(n + 55);
	else
		ft_putchar(n % 16 + '0');
}

size_t	ft_nbrlenbase(long long nbr, int base)
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

int		ft_putwhile(char c, int i)
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_return_value++;
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

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_iswhitespace(char c)
{
	return (c == '\n' || c == '\t' || c == ' ' ||
		c == '\v' || c == '\f' || c == '\r');
}

int		ft_negative(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

int		ft_isdigit_signed(int c)
{
	return ((c <= 57 && c >= 48) || (c == '-') || (c == '+'))
}

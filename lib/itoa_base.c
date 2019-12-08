/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:55:08 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/08 18:45:01 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int		num_size(int n, int base)
{
	int	i;

	i = 1;
	if (n == 0)
		return (i);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

static int	base_type(int n, int base, char c)
{
	if (n % base < 10)
		return (n % base + '0');
	if (c == 'X')
		return (n % base + 55);
	if (c == 'x')
		return (n % base + 87);
	return (0);
}

static char		*ft_itoa_base(int n, int base, char c)
{
	int		len;
	char	*str;

	len = num_size(n, base);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = 0;
	len--;
	while (n >= base)
	{
		str[len] = base_type(n, base, c);
		len--;
		n = n / base;
	}
	str[len] = base_type(n, base, c);
	return (str);
}

int		main(void)
{
	int base;

	base = 10;
	while (base <= 36)
	{
		printf("base: %i, %s\n", base, ft_itoa_base(999, base, 'X'));
		base++;
	}
}

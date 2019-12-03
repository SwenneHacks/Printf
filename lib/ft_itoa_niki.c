/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_niki.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 19:57:03 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/03 20:42:41 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	num_size(int n, int base)
{
	int 	i;

	i = 1;
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
	if (c == 'x')
		return (n % base + 87);
	return (n % base + 55);	
}

char		*ft_itoa_base(long long n, int base, char c)
{
	int		len;
	char 	*str;

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
	int i = 2;

	while (i <= 36)
	{
		printf("base: %i, %s\n", i, ft_itoa_base(999, i, 'x'));
		i++;	
	}
}

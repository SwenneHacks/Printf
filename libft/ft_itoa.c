/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:55:08 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/28 21:52:09 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_memlen(int len)
{
	char	*res;

	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	res[len - 1] = '\0';
	return (res);
}

static char		*ft_longnull(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

static char		ft_solver(int sign, int len, int n, char *res)
{
	int i;

	i = -1;
	while (i + 1 < len - sign)
	{
		i++;
		res[len - 1 - i] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (*res);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*res;

	sign = n < 0;
	len = ft_numlen(n);
	res = ft_memlen(len + 1);
	if (res == NULL)
		return (NULL);
	if (n == -2147483648 || n == 0)
		return (ft_longnull(n));
	if (sign)
	{
		*res = '-';
		n *= -1;
	}
	ft_solver(sign, len, n, res);
	return (res);
}

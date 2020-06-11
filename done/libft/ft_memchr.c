/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:11:38 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/28 19:15:20 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cha;

	i = 0;
	str = (unsigned char *)(s);
	cha = (unsigned char)c;
	while (n > i)
	{
		if (str[i] == cha)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

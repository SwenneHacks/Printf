/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:13:21 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/17 14:04:10 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	cha;

	i = ft_strlen(s);
	cha = (char)c;
	str = (char *)s;
	while (str[i] != cha)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&str[i]);
}

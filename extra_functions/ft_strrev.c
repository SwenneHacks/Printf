/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 19:39:31 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 15:27:11 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	rev;
	int		len;
	int		index;

	len = ft_strlen(s);
	index = 0;
	while (index < len / 2)
	{
		rev = s[index];
		s[index] = s[len - index - 1];
		s[len - index - 1] = rev;
		index++;
	}
	return (s);
}

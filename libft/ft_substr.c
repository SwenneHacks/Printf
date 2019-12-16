/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:40:42 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/28 20:25:03 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			index;
	unsigned int	s_len;

	index = 0;
	if ((!s))
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s && len != 0)
	{
		sub[index] = s[start];
		start++;
		index++;
		len--;
	}
	sub[index] = '\0';
	return (sub);
}

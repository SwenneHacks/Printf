/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 20:37:02 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/16 14:16:30 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char *str;

	str = ft_memccpy(dst, src, '\0', dstsize);
	if (!str && dstsize != 0)
		dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}

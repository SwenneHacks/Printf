/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:14:27 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/22 14:05:28 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*objects;

	objects = (void *)malloc(count * size);
	if (objects == NULL)
		return (NULL);
	ft_bzero(objects, count * size);
	return (objects);
}

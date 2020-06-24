/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:14:27 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/17 14:01:46 by swofferh      ########   odam.nl         */
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

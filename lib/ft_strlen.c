/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_len.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:31:45 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 14:52:11 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

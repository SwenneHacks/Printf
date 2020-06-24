/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lenbase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 21:55:21 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/19 21:57:22 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions checks the length of the number depending of base variable.
*/

size_t	ft_lenbase(long long nbr, int base)
{
	size_t len;

	len = 1;
	if (nbr < 0)
		len++;
	if (base == 1)
	{
		if (nbr < 0)
			nbr = nbr * -1;
		return ((size_t)nbr + len);
	}
	while (nbr / base != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

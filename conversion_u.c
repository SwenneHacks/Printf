/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   argument_d.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:26:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:38:16 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_u_argument(void)
{
	unsigned int	nbr;
	//int	len;

	nbr = (unsigned int)va_arg(g_argument, unsigned int);
	//len = ft_lenbase(nbr, 10);
	if (g_conversion == 'u')
		ft_putnbr(nbr);
	if (g_conversion == 'o')
		ft_putocta(nbr);
}

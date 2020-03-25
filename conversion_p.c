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

void	ft_p_argument(void)
{
	unsigned long	nbr;
	//int	len;

	nbr = (unsigned long)va_arg(g_argument, void *);
	//len = ft_lenbase(nbr, 16);
	if (g_conversion == 'p')
		ft_putstr("0x");
		ft_puthexa(nbr, 'x');
}


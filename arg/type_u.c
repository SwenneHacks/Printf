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

#include "../printf.h"

void	ft_u_argument(t_info *node)
{
	unsigned int	nbr;
	//int	len;

	nbr = (unsigned int)va_arg(node->argument, unsigned int);
	//len = ft_lenbase(nbr, 10);
	if (node->conversion == 'u')
		if(nbr < 0)
			// ft_putnbr(node, nbr * -1);
		pt_putnbr(node, nbr);
	if (node->conversion == 'o')
		pt_putocta(node, nbr);
}

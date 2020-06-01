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

void	ft_p_argument(t_info *node)
{
	unsigned long	nbr;
	int	len;

	nbr = (unsigned long)va_arg(node->argument, void *);
	len = ft_lenbase(nbr, 16);
	if (node->conversion == 'p')
		pt_putstr(node, "0x");
		pt_puthexa(node, nbr, 'x');
}

void	ft_no_argument(t_info *node)
{
	if (node->period == TRUE)
		{
			if (node->flag == ZERO)
				pt_putlen(node, ' ', node->width - node->precision);
			if (node->flag == NOFLAG)
				pt_putlen(node, ' ', node->width - node->precision);
			pt_putchar(node, '%');
			if (node->flag == MINUS)
				pt_putlen(node, ' ', node->width - node->precision);
			
		}
		else if (node->period == FALSE)
		{
			if (node->width > 0 && node->flag == ZERO)
				pt_putlen(node, '0', node->width - 1);
			if (node->width > 0 && node->flag == NOFLAG)
				pt_putlen(node, ' ', node->width - 1);
			pt_putchar(node, '%');
			if (node->width > 0 && node->flag == MINUS)
				pt_putlen(node, ' ', node->width - 1);
		}
}

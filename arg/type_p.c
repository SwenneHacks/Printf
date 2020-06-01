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
	int ox;
	int	len;
	int width;
	int precision;

	ox = 2;
	width = node->width;
	precision = node->precision;
	nbr = (unsigned long)va_arg(node->argument, void *);
	len = ft_lenbase(nbr, 16);
	if (nbr == 0 && node->period == TRUE && precision == 0)
	{
		if (node->flag == NOFLAG  || node->flag == ZERO)
			pt_putlen(node, ' ', width - ox);
		pt_putstr(node, "0x");
		if (node->flag == MINUS)
			pt_putlen(node, ' ', width - ox);
	}
	else
	{
		if (node->flag == NOFLAG)
			pt_putlen(node, ' ', width - ft_maxof(len, precision) - ox);
		pt_putstr(node, "0x");
		if (precision > len)
			pt_putlen(node, '0', precision - len);
		if (node->flag == ZERO)
			pt_putlen(node, '0', width - ft_maxof(len, precision) - ox);
		pt_puthexa(node, nbr, 'x');
		if (node->flag == MINUS)
			pt_putlen(node, ' ', width - ft_maxof(len, precision) - ox);
	}
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

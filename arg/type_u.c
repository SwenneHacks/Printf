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
	int	nbr;
	int len;
	int width;
	int precision;
	int *u;

	u = &nbr;
	width = node->width;
	precision = node->precision;
	nbr = va_arg(node->argument, unsigned int);
	len = ft_lenbase(nbr, 10);
	//printf("len  |%d|", len);
	if (node->conversion == 'o')
		pt_putocta(node, nbr);
	if (node->conversion == 'u')
	{
		if (nbr < 0)
		{
			if (node->flag == NOFLAG)
				pt_putlen(node, ' ', width - ft_maxof(precision, 10));
			if (precision > 10)
				pt_putlen(node, '0', precision - 10);
			if (node->flag == ZERO)
				pt_putlen(node, '0', width - ft_maxof(precision, 10));
			pt_putocta(node, (unsigned int)u * -1);
			if (node->flag == MINUS)
				pt_putlen(node, ' ', width - ft_maxof(precision, 10));
		}
		else if (nbr == 0)
		{
			if (node->period == TRUE && precision == 0)
				pt_putlen(node, ' ', width);
			else
			{
				if (node->flag == NOFLAG)
					pt_putlen(node, ' ', width - ft_maxof(precision, len));
				if (node->flag == ZERO)
				{
					if (node->period == FALSE)
						pt_putlen(node, '0', width - 1);
					else
						pt_putlen(node, ' ', width - precision);
				}
				if (precision > 0)
				 	pt_putlen(node, '0', precision - 1);
				pt_putnbr(node, nbr);
				if (node->flag == MINUS)
				{
					if (node->period == FALSE)
						pt_putlen(node, ' ', width - 1);
					else
						pt_putlen(node, ' ', width - precision);
				}
			}
		}
		else
		{
			if (!node->period)
			{
				if (node->flag == MINUS)
				{
					pt_putnbr(node, pt_putsign(node, nbr));
					pt_putlen(node, ' ', node->width - len);
				}
				else if (node->flag == ZERO)
				{
					nbr = pt_putsign(node, nbr);
					pt_putlen(node, '0', node->width - len);
					pt_putnbr(node, nbr);
				}
				else if (node->flag == NOFLAG)
				{
					pt_putlen(node, ' ', node->width - len);
					pt_putnbr(node, pt_putsign(node, nbr));
				}
			}
			else
			{
				if (node->flag == ZERO || node->flag == NOFLAG)
					pt_putlen(node, ' ', width - ft_maxof(precision, len));
				if (precision > len)
					pt_putlen(node, '0', precision - len);
				pt_putnbr(node, (unsigned int)nbr);
				if (node->flag == MINUS)
				{
					if (width < precision)
						pt_putlen(node, ' ', precision - width - len);
					else
						pt_putlen(node, ' ', width - ft_maxof(precision, len));
				}
			}
		}
	}
}
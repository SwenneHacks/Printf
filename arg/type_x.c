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

void	width_u(t_info *node, int nbr, int len)
{
	if (node->flag == ZERO)
		pt_putlen(node, '0', node->width - len);
	if (node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - len);
	if (node->conversion == 'X')
		pt_puthexa(node, nbr, 'X');
	if (node->conversion == 'x')
		pt_puthexa(node, nbr, 'x');
	if (node->flag == MINUS)
		pt_putlen(node, ' ', node->width - len);
}

void	preci_u(t_info *node, int nbr, int len)
{
	if (node->precision > len)
		pt_putlen(node, '0', node->precision - len);
	if (node->precision > len && node->flag == ZERO)
		pt_putlen(node, '0', node->width - ft_maxof(node->precision, len));
	if (node->precision < len || node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
	if (node->conversion == 'X')
		pt_puthexa(node, nbr, 'X');
	if (node->conversion == 'x')
		pt_puthexa(node, nbr, 'x');
	if (node->flag == MINUS)
	{
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
		if (node->width < node->precision)
			pt_putlen(node, ' ', node->width - len);
	}
}

void	ft_x_argument(t_info *node)
{
	int	nbr;
	int	len;

	nbr = va_arg(node->argument, unsigned int);
	len = ft_lenbase(nbr, 16);
	if (nbr < 0)
	{
		if ((node->flag == NOFLAG || node->flag == ZERO) && (node->period == TRUE))
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, 8));
		if (node->width >= 8 && node->flag == ZERO && node->period == FALSE)
			pt_putlen(node, '0', node->width - 8);
		if (node->precision > 8 && node->flag != MINUS)
			pt_putlen(node, '0', node->precision - 8);
		if (node->conversion == 'x')
			pt_putstr(node, "fffffff7");
		else
			pt_putstr(node, "FFFFFFF7");
		if (node->width > 8 && node->flag == MINUS)
			pt_putlen(node, ' ', node->width - 8);
	}
	else if (nbr == 0)
	{
		if (node->period == TRUE && node->flag != MINUS)
			pt_putlen(node, ' ', node->width - node->precision);
		if (node->precision > 0)
			pt_putlen(node, '0', node->precision);
		if (node->precision == 0 && node->width > 0 && node->flag == ZERO)
			pt_putlen(node, '0', node->width - 1);
		if (node->precision == 0 && node->width >= 0 && node->flag != MINUS)
			pt_putchar(node, '0');
		if (node->flag == MINUS)
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
	}
	else if (!node->width && !node->period)
	{
		if (node->conversion == 'X')
			pt_puthexa(node, nbr, 'X');
		if (node->conversion == 'x')
			pt_puthexa(node, nbr, 'x');
	}
	else if (!node->period)
		width_u(node, nbr, len);
	else
		preci_u(node, nbr, len);

	// printf("\nlen  |%d|\nnbr  |%d|\n", len, nbr);
}



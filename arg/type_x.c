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

void	hashtag(t_info *node)
{
	if (node->sign == HASH)
	{
		if (node->conversion == 'x')
			pt_putstr(node, "0x");
		if (node->conversion == 'X')
			pt_putstr(node, "0X");
	}	
}

void	puthexa(t_info *node, unsigned int nbr)
{
	if (node->conversion == 'X')
		pt_puthexa(node, nbr, 'X');
	if (node->conversion == 'x')
		pt_puthexa(node, nbr, 'x');
}

void	width_u(t_info *node, int nbr, int len)
{
	int prefix;

	prefix = 0;
	if (node->sign == HASH)
		prefix = 2;
	if (node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - len - prefix);
	hashtag(node);
	if (node->flag == ZERO)
		pt_putlen(node, '0', node->width - len - prefix);
	puthexa(node, nbr);
	if (node->flag == MINUS)
		pt_putlen(node, ' ', node->width - len - prefix);
}

void	preci_u(t_info *node, unsigned int nbr, int len)
{
	int prefix;

	prefix = 0;
	if (node->sign == HASH)
		prefix = 2;
	if (node->width > node->precision && node->flag == ZERO)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len) - prefix);
	if (node->flag == NOFLAG)
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len) - prefix);
	hashtag(node);
	if (node->precision > len)
		pt_putlen(node, '0', node->precision - len);
	puthexa(node, nbr);
	if (node->flag == MINUS)
	{
		pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len) - prefix);
		if (node->width < node->precision)
			pt_putlen(node, ' ', node->width - len);
	}
}

void	ft_x_argument(t_info *node)
{
	unsigned int	nbr;
	int	neg;
	int	len;

	nbr = (unsigned int)va_arg(node->argument, unsigned int);
	len = ft_lenbase(nbr, 16);
	neg = nbr;
	if (neg < 0 || nbr == UNS_MAX)
	{
		int prefix;

		prefix = 0;
		if (node->sign == HASH)
			prefix = 1;
		if ((node->flag == NOFLAG || node->flag == ZERO) && (node->period == TRUE))
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, 8) - prefix);
		if (node->width >= 8 && node->flag == NOFLAG && node->period == FALSE)
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, 8) - prefix);
		hashtag(node);
		if (node->width >= 8 && node->flag == ZERO && node->period == FALSE)
			pt_putlen(node, '0', node->width - ft_maxof(node->precision, 8) - prefix);
		if (node->precision > 8)
			pt_putlen(node, '0', node->precision - 8);
		if (nbr == UNS_MAX)
		{
			if (node->conversion == 'x')
				pt_putstr(node, "ffffffff");
			if (node->conversion == 'X')
				pt_putstr(node, "FFFFFFFF");
		}
		else if (node->conversion == 'x')
			pt_putstr(node, "fffffff7");
		else if (node->conversion == 'X')
			pt_putstr(node, "FFFFFFF7");
		if (node->width > 8 && node->flag == MINUS)
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, 8) - prefix);
	}
	else if (nbr == 0)
	{
		if (node->period == FALSE && node->flag == NOFLAG)
			pt_putlen(node, ' ', node->width - ft_maxof(node->precision, len));
		if (node->period == TRUE && node->flag != MINUS)
			pt_putlen(node, ' ', node->width - node->precision);
		if (node->precision > 0)
			pt_putlen(node, '0', node->precision);
		if (node->precision == 0 && node->width > 0 && node->flag == ZERO)
			pt_putlen(node, '0', node->width - ft_maxof(node->precision, len));
		if (node->period == FALSE && node->width >= 0)
			pt_putchar(node, '0');
		if (node->period == FALSE && node->flag == MINUS)
			pt_putlen(node, ' ', node->width - len);
		if (node->period == TRUE && node->flag == MINUS)
			pt_putlen(node, ' ', node->width - node->precision);
	}
	else if (!node->width && !node->period)
	{
		hashtag(node);
		puthexa(node, nbr);
	}
	else if (!node->period)
		width_u(node, nbr, len);
	else
		preci_u(node, nbr, len);

	// printf("\nlen  |%d|\nnbr  |%d|\n", len, nbr);
}



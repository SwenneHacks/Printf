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

void	width_d(int nbr, int len)
{
	if (nbr > 0 && g_sign != 0)
		len++;
	if (g_flag == MINUS)
	{
		ft_putnbr(ft_putsign(nbr));
		ft_putlen(' ', g_width - len);
	}
	else if (g_flag == ZERO)
	{
		nbr = ft_putsign(nbr);
		ft_putlen('0', g_width - len);
		ft_putnbr(nbr);
	}
	else if (g_flag == NOFLAG)
	{
		ft_putlen(' ', g_width - len);
		ft_putnbr(ft_putsign(nbr));
	}
}

void	preci_d(int nbr, int len)
{
	int sign;
	if (nbr < 0)
		sign = TRUE;
	if (g_flag == MINUS)
	{
		nbr = ft_putsign(nbr);
		ft_putlen('0', g_precision - len + sign);
		ft_putnbr(nbr);
	}
	if (g_width)
	{
		if (g_precision < g_width)
		{
			ft_putlen(' ', g_width - ft_maxof(g_precision, len) - sign);
			if (g_precision < len)
				ft_putlen(' ', sign);
		}
		if (g_width > 9)
			ft_putlen(' ', g_width % 9 - len - sign);
	}
	if (g_flag == ZERO || g_flag == NOFLAG)
	{
		nbr = ft_putsign(nbr);
		ft_putlen('0', g_precision - len + sign);
		ft_putnbr(nbr);
	}
}

void	ft_d_argument(void)
{
	int	nbr;
	int	len;

	nbr = va_arg(g_argument, int);
	len = ft_lenbase(nbr, 10);
	if (nbr == 0)
	{
		if (g_period == TRUE)
		{
			if (g_sign != 0)
				g_width--;
			if (g_flag == ZERO)
				ft_putlen(' ', g_width - g_precision);
			if (g_flag == NOFLAG)
				ft_putlen(' ', g_width - g_precision);
			if (g_sign != 0)
				ft_putsign(nbr);
			ft_putlen('0', g_precision);
			if (g_flag == MINUS)
				ft_putlen(' ', g_width - g_precision);
			
		}
		else if (g_period == FALSE)
		{
			if (g_width > 0 && g_flag == ZERO)
				ft_putlen('0', g_width - 1);
			if (g_width > 0 && g_flag == NOFLAG)
				ft_putlen(' ', g_width - 1);
			ft_putnbr(ft_putsign(nbr));
			if (g_width > 0 && g_flag == MINUS)
				ft_putlen(' ', g_width - 1);
		}
	}
	else if (!g_period)
	{
		if (!g_width)
			ft_putnbr(ft_putsign(nbr));
		else
			width_d(nbr, len);
	}
	else
		preci_d(nbr, len);

	// printf("len  |%d|", len);
}
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
	if (g_width > 0 && g_flag == SPACE)
	{
		ft_putnbr(nbr);
		ft_putlen(' ', ft_sign(g_width) - len);
	}	
	else if (g_width != 0 && g_flag == MINUS)
	{
		ft_putnbr(nbr);
		ft_putlen(' ', ft_sign(g_width) - len);
	}
	else if (g_width > 0 && g_flag == ZERO)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		ft_putlen('0', g_width - len);
		ft_putnbr(nbr);
	}
	else if (g_width > 0 && g_flag == NOFLAG)
	{
		ft_putlen(' ', g_width - len);
		ft_putnbr(nbr);
	}
}

void	preci_d(int nbr, int len)
{
	if (g_width >= 0 && g_flag == MINUS)
	{
		ft_putlen(nbr, len);
		ft_putlen(' ', g_precision - len);
	}
	else if (g_flag == ZERO)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
			len--;
		}
		ft_putlen('0', g_precision - len);
		ft_putnbr(nbr);
	}
	else if (g_width >= 0 && g_flag == NOFLAG)
	{
		if (g_width > 0)
			ft_putlen(' ', g_width - len);
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
			len--;
		}
		if (!g_width)
			ft_putlen('0', g_precision - len);
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
		if (!g_precision && g_flag == MINUS)
			ft_putchar(' ');
		if (g_precision > 0 && g_width >= 0)
		{
			if (g_flag == ZERO)
			{
				len++;
				ft_putlen(' ', g_precision - len);
			}
			ft_putlen('0', ft_sign(g_precision));
			if (g_flag == MINUS)
			{
				len++;
				ft_putlen(' ', g_precision - len);
			}
		}
		else if (!g_precision && !g_width)
		{
		}
	}
	else if (!g_period)
	{
		if (!g_width)
			ft_putnbr(nbr);
		width_d(nbr, len);
	}
	else
		preci_d(nbr, len);
}
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

void	ft_no_period(int nbr, int len)
{
	if (!g_minfield)
		ft_putnbr(nbr);
	else if (g_flag == MINUS && g_minfield != 0)
	{
		ft_putnbr(nbr);
		ft_putlen(' ', ft_vabs(g_minfield) - len);
	}
	else if (g_flag == ZERO && g_minfield > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		ft_putlen('0', g_minfield - len);
		ft_putnbr(nbr);
	}
	else if (g_flag == NOFLAG && g_minfield > 0)
	{
		ft_putlen(' ', g_minfield - len);
		ft_putnbr(nbr);
	}
}

void	ft_d_argument(void)
{
	int	nbr;
	int	len;

	nbr = va_arg(g_argument, int);
	len = ft_lenbase(nbr, 10);
	if (!g_period)
		ft_no_period(nbr, len);
	// else
	// 	ft_period(nbr, char_nbr);
}

// void	ft_period(int nbr, int char_nbr)
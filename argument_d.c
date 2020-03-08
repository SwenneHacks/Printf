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

void	ft_no_period(int nbr, int char_nbr)
{
	if (!g_minfield)
		ft_putnbr(nbr);
	else if (g_flag == 1 && g_minfield != 0)
	{
		ft_putnbr(nbr);
		ft_putchar_while(' ', ft_vabs(g_minfield) - char_nbr);
	}
	else if (!g_flag && g_minfield > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		ft_putchar_while('0', g_minfield - char_nbr);
		ft_putnbr(nbr);
	}
	else if (g_flag == -1 && g_minfield > 0)
	{
		ft_putchar_while(' ', g_minfield - char_nbr);
		ft_putnbr(nbr);
	}
}

void	ft_d_argument(void)
{
	int	nbr;
	int	char_nbr;

	nbr = va_arg(g_ap, int);
	char_nbr = ft_calcnbr(nbr, 0, 10);
	if (!g_period)
		ft_no_period(nbr, char_nbr);
	// else
	// 	ft_period(nbr, char_nbr);
}

// void	ft_period(int nbr, int char_nbr)
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

// void	ft_no_dot(int nbr, int len)
// {
// 	if (!g_width)
// 		ft_puthexa(nbr, 'x');
// 	else if (g_flag == MINUS && g_width != 0)
// 	{
// 		ft_puthexa(nbr, 'x');
// 		ft_putlen(' ', ft_vabs(g_width) - len);
// 	}
// 	else if (g_flag == ZERO && g_width > 0)
// 	{
// 		ft_putlen('0', g_width - len);
// 		ft_puthexa(nbr, 'x');
// 	}
// 	else if (g_flag == NOFLAG && g_width > 0)
// 	{
// 		ft_putlen(' ', g_width - len);
// 		ft_puthexa(nbr, 'x');
// 	}
// 	if (g_conversion == 'X')
// 		ft_puthexa(nbr, 'X');
// }

void	ft_x_argument(void)
{
	int	nbr;
	//int	len;

	nbr = va_arg(g_argument, unsigned int);
	//len = ft_lenbase(nbr, 16);
	if (g_conversion == 'x')
		ft_puthexa(nbr, 'x');
	if (g_conversion == 'X')
		ft_puthexa(nbr, 'X');
	// if (!g_period)
	// 	ft_no_dot(nbr, len);
	// else
	// 	ft_period(nbr, char_nbr);
}

// void	ft_period(int nbr, int char_nbr)

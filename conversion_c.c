/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   argument_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:31:04 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:32:15 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_argument(void)
{
	char	c;

	c = va_arg(g_argument, int);
	if (g_flag == NOFLAG && !g_minfield)
		ft_putchar(c);
	if ((g_minfield != 1 && g_flag == MINUS))
	{
		ft_putchar(c);
		ft_putlen(' ', (ft_vabs(g_minfield) - 1));
	}
	else if (g_flag == NOFLAG && g_minfield > 0)
	{
		ft_putlen(' ', g_minfield - 1);
		ft_putchar(c);
	}
}

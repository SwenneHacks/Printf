/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   argument_s.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:30:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:32:07 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	width_s(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > g_width)
		ft_putstr(str);
	else
	{
		if (g_width != 1 && g_flag == MINUS)
		{
			ft_putstr(str);
			ft_putlen(' ', g_width - len);
		}
		else if (!g_width)
			ft_putstr(str);
		else if (g_width > 0 && g_flag == NOFLAG)
		{
			ft_putlen(' ', g_width - len);
			ft_putstr(str);
		}
	}
}

int		len_str(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= g_precision)
		return (len);
	else
		return (g_precision);
}

void	preci_s(char *str)
{
	int i;
	int	len;

	i = 0;
	if (g_flag == MINUS)
	{
		while (i < g_precision && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		ft_putlen(' ', g_width - i);
	}
	else if (!g_width)
	{
		while (i < g_precision && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		len = len_str(str);
		ft_putlen(' ', g_width - len);
		while (i < len && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_s_argument(void)
{
	char *str;

	str = va_arg(g_argument, char *);
	if (str == NULL)
		str = "(null)";
	if (!g_period)
		width_s(str);
	else
		preci_s(str);
}

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

#include "printf.h"

void	ft_s_argument_noperiod(char *str)
{
	int	lenstr;

	lenstr = ft_strlen(str);
	if (lenstr > g_minfield)
		ft_putstr(str);
	else
	{
		if (g_flag == MINUS && g_minfield > 0)
		{
			ft_putstr(str);
			ft_putlen(' ', g_minfield - lenstr);
		}
		else if (!g_minfield)
			ft_putstr(str);
		else if (g_flag == NOFLAG && g_minfield > 0)
		{
			ft_putlen(' ', g_minfield - lenstr);
			ft_putstr(str);
		}
	}
}

int		ft_nb_str(char *str)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (len_str <= g_maxfield)
		return (len_str);
	else
		return (g_maxfield);
}

void	ft_s_argument_period(char *str)
{
	int i;
	int	nb_str;

	i = 0;
	if (g_flag == 1)
	{
		while (i < g_maxfield && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		ft_putlen(' ', g_minfield - i);
	}
	else if (!g_minfield)
	{
		while (i < g_maxfield && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		nb_str = ft_nb_str(str);
		ft_putlen(' ', g_minfield - nb_str);
		while (i < nb_str && str[i])
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
		ft_s_argument_noperiod(str);
	else
		ft_s_argument_period(str);
}

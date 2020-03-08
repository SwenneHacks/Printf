/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_specifiers.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:27:06 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:35:21 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_checkpercent(const char *str)
{
	int i;
	int nb_print_percent;

	i = 0;
	while (str[i] == '%')
		i++;
	nb_print_percent = i / 2;
	while (nb_print_percent)
	{
		ft_putchar('%');
		nb_print_percent--;
	}
	if (i % 2 == 1)
	{
		i += ft_check_after_percent(str + i);
	}
	return (i);
}

int		ft_check_after_percent(const char *str)
{
	int i;

	i = 0;
	i += ft_checkflags(str + i);
	while (str[i] == '-')
		i++;
	i += ft_checkminfield(str + i);
	i += ft_checkperiod_maxfield(str + i);
	i += ft_checkargument(str + i);
	// printf("flag %d\n", g_flag);
	// printf("min %d\n", g_minfield);
	// printf("period %d\n", g_period);
	// printf("max %d\n", g_maxfield);
	// printf("argument %c\n", g_argument);
	return (i);
}

void	init_globalv(void)
{
	g_return = 0;
	g_flag = -1;
	g_minfield = 0;
	g_period = 0;
	g_maxfield = 0;
}

int		ft_vabs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

int		ft_checkflags(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '0')
	{
		g_flag = 0;
		i++;
		return (i);
	}
	else if (str[i] == '-')
	{
		g_flag = 1;
		i++;
		return (i);
	}
	else
	{
		g_flag = -1;
		return (i);
	}
}

int		ft_checkminfield(const char *str)
{
	int i;

	i = 0;
	if ((str[i] == '*') || ft_isdigit_signed(str[i]))
	{
		if (('0' <= str[i] && str[i] <= '9') || (str[i] == '-'))
		{
			g_minfield = ft_atoi(str);
			while (('0' <= str[i] && str[i] <= '9') || str[i] == '-')
				i++;
			return (i);
		}
		else
		{
			g_minfield = va_arg(g_ap, int);
			i++;
			return (i);
		}
	}
	else
		g_minfield = 0;
	return (i);
}

int		ft_checkperiod_maxfield(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		g_period = 1;
		i++;
		i += ft_checkmaxfield(str + i);
		return (i);
	}
	return (i);
}

int		ft_checkmaxfield(const char *str)
{
	int i;

	i = 0;
	if ((str[i] == '*') || ft_isdigit_signed(str[i]))
	{
		if (('0' <= str[i] && str[i] <= '9') || (str[i] == '-'))
		{
			g_maxfield = ft_atoi(str);
			while ('0' <= str[i] && str[i] <= '9')
				i++;
			return (i);
		}
		else
		{
			g_maxfield = va_arg(g_ap, int);
			i++;
			return (i);
		}
	}
	else
	{
		g_maxfield = 0;
		return (i);
	}
	return (i);
}

int		ft_checkargument(const char *str)
{
	int		i;
	int		j;
	char	*conversion;

	i = 0;
	j = 0;
	conversion = "cspdiuxX";
	while (str[i])
	{
		if (str[i] == conversion[j])
		{
			g_argument = conversion[j];
			i += ft_go_to_argument(g_argument);
			return (i);
		}
		j++;
	}
	return (i);
}

int		ft_go_to_argument(char g_argument)
{
	int i;

	i = 0;
	if (g_argument == 'c')
		ft_c_argument();
	else if (g_argument == 'd' || g_argument == 'i')
		ft_d_argument();
	else if (g_argument == 's')
		ft_s_argument();
	else if (g_argument == 'x' || g_argument == 'X')
		ft_printf("Haven't done this one yet =P");
	i++;
	return (i);
}

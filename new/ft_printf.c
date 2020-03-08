/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 17:27:32 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 19:43:32 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void		ft_printf(const char *str, ...)
{
	unsigned int	index;
	t_info			info;

	index = 0;
	va_start(g_arguments, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%')
			index += ft_percentage(str + index, &info);
		else
		{
			write(1, &str[index], 1);
		}
		index++;
	}
	va_end(g_arguments);
	return ;
}

int		ft_percentage(const char *str, t_info *info)
{
	int		i;
	
	i += ft_checkflags(str + i);
	if (str[1] == '%')
	{
		ft_putchar('%');
		info.conversion = '%'
	}
	while (str[i] == '-')
		i++;
	i += check_minfield(str + i);
	i += check_maxfield(str + i);
	i += check_argument(str + i);
	return (i);
}

void	init_globalv(void)
{
	g_return_value = 0;
	g_minfield = 0;
	g_maxfield = 0;
	g_flag = -1;
	g_dot = 0;
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

int		check_minfield(const char *str)
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

int		ft_check_maxfield(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		g_period = 1;
		i++;
		i += check_maxfield(str + i);
		return (i);
	}
	return (i);
}



int		ft_checkmaxfield(const char *format)
{
	int i;

	i = 0;
	if ((format[i] == '*') || ft_isdigit_or_signe(format[i]))
	{
		if (('0' <= format[i] && format[i] <= '9') || (format[i] == '-'))
		{
			g_maxfield = ft_atoi(format);
			while ('0' <= format[i] && format[i] <= '9')
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

int		ft_checkargument(const char *format)
{
	int		i;
	int		j;
	char	*checkargument;

	i = 0;
	j = 0;
	checkargument = "cspdiuxX";
	while (format[i])
	{
		if (format[i] == checkargument[j])
		{
			g_argument = checkargument[j];
			i += ft_go_to_argument(g_argument);
			return (i);
		}
		j++;
	}
	return (i);
}

int		ft_go_to_argument(char g_argument)
{
	//csdiuXxp%
	int i;

	i = 0;
	if (g_argument == 'c')
		ft_c_argument();
	else if (g_argument == 'd' || g_argument == 'i')
		ft_d_argument();
	else if (g_argument == 's')
		ft_s_argument();
	else if (g_argument == 'x' || g_argument == 'X')
		ft_xX_argument();
	i++;
	return (i);
}

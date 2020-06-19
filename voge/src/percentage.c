/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percentage.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:27:06 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/19 16:49:00 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_percentage(t_info *node, const char *str)
{
	int i;
	int duo_percent;

	i = 0;
	while (str[i] == '%')
		i++;
	duo_percent = i / 2;
	while (duo_percent)
	{
		pt_putchar(node, '%');
		duo_percent--;
	}
	if (i % 2 == 1)
	{
		i += bonus_flags(node, str + i);
		i += ft_flags(node, str + i);
		i += ft_width(node, str + i);
		i += ft_precision(node, str + i);
		i += ft_argument(node, str + i);
	}
	return (i);
}

int		bonus_flags(t_info *node, const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
	{
		node->sign = SPACE;
		i++;
	}
	while (str[i] == '#')
	{
		node->sign = HASH;
		i++;
	}
	if (str[i] == '+')
	{
		node->sign = PLUS;
		while (str[i] == '+')
			i++;
	}
	return (i);
}

int		ft_flags(t_info *node, const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		node->flag = MINUS;
		while (str[i] == '-')
			i++;
	}
	else if (str[i] == '0')
	{
		node->flag = ZERO;
		i++;
		while (str[i] == '0')
			i++;
		if (str[i] == '-')
		{
			node->flag = MINUS;
			i++;
		}
	}
	else
		node->flag = NOFLAG;
	return (i);
}

int		ft_width(t_info *node, const char *str)
{
	int i;

	i = 0;
	if (('0' <= str[i] && str[i] <= '9') || str[i] == '-')
	{
		node->width = ft_atoi(str);
		while (('0' <= str[i] && str[i] <= '9'))
			i++;
	}
	if (str[i] == '*')
	{
		node->width = va_arg(node->argument, int);
		i++;
	}
	if (node->width < 0)
	{
		node->flag = MINUS;
		node->width *= -1;
	}
	else
		node->width = 0;
	return (i);
}

int		ft_precision(t_info *node, const char *str)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		node->period = TRUE;
		i++;
		i += ft_asterik(node, str + i);
		return (i);
	}
	return (i);
}

int		ft_asterik(t_info *node, const char *str)
{
	int i;

	i = 0;
	if (('0' <= str[i] && str[i] <= '9') || (str[i] == '-'))
	{
		node->precision = ft_atoi(str);
		while ('0' <= str[i] && str[i] <= '9')
			i++;
		return (i);
	}
	else if (str[i] == '*')
	{
		node->precision = va_arg(node->argument, int);
		if (node->precision < 0)
			node->precision *= -1;
		i++;
		return (i);
	}
	else
	{
		node->precision = 0;
		return (i);
	}
	return (i);
}

int		ft_argument(t_info *node, const char *str)
{
	int		i;
	int		j;
	char	*conv;

	i = 0;
	j = 0;
	conv = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == conv[j])
		{
			node->conversion = conv[j];
			i += ft_conversion(node, node->conversion);
			return (i);
		}
		j++;
	}
	return (i);
}

int		ft_conversion(t_info *node, char conversion)
{
	if (conversion == 'c')
		ft_c_argument(node);
	else if (conversion == 'd' || conversion == 'i')
		ft_d_argument(node);
	else if (conversion == 's')
		ft_s_argument(node);
	else if (conversion == 'x' || conversion == 'X')
		ft_x_argument(node);
	else if (conversion == 'p')
		ft_p_argument(node);
	else if (conversion == 'u' || conversion == 'o')
		ft_u_argument(node);
	else if (conversion == '%')
		ft_no_argument(node);
	return (1);
}

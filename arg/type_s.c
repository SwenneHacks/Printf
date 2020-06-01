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

void	width_s(t_info *node, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > node->width)
		pt_putstr(node, str);
	else
	{
		if (node->width > 0 && node->flag == MINUS)
		{
			pt_putstr(node, str);
			pt_putlen(node, ' ', node->width - len);
		}
		else if (!node->width)
			pt_putstr(node, str);
		else if (node->width > 0 && node->flag == NOFLAG)
		{
			pt_putlen(node, ' ', node->width - len);
			pt_putstr(node, str);
		}
		else if (node->width > 0 && node->flag == ZERO)
		{
			pt_putlen(node, '0', node->width - len);
			pt_putstr(node, str);
		}
	}
}

int		len_str(t_info *node, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= node->precision)
		return (len);
	else
		return (node->precision);
}

void	preci_s(t_info *node, char *str)
{
	int i;
	int	len;

	i = 0;
	if (node->flag == MINUS)
	{
		while (i < node->precision && str[i])
		{
			pt_putchar(node, str[i]);
			i++;
		}
		pt_putlen(node, ' ', node->width - i);
	}
	else if (!node->width)
	{
		while (i < node->precision && str[i])
		{
			pt_putchar(node, str[i]);
			i++;
		}
	}
	else
	{
		len = len_str(node, str);
		pt_putlen(node, ' ', node->width - len);
		while (i < len && str[i])
		{
			pt_putchar(node, str[i]);
			i++;
		}
	}
}

void	ft_s_argument(t_info *node)
{
	char *str;

	str = va_arg(node->argument, char *);
	if (str == NULL)
		str = "(null)";
	if (!node->period)
		width_s(node, str);
	else
		preci_s(node, str);
}

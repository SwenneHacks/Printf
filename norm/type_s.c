/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:30:52 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/12 23:29:52 by sofferha      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	width_s(t_info *node, char *str, int len)
{
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

void	str_loop(t_info *node, char *str, int i)
{
	pt_putchar(node, str[i]);
	i++;
}

void	preci_s(t_info *node, char *str, int len, int i)
{
	if (node->flag != MINUS)
		pt_putlen(node, ' ', node->width - len);
	while (i < node->precision && str[i])
	{
		pt_putchar(node, str[i]);
		i++;
	}
	if (node->flag == MINUS)
		pt_putlen(node, ' ', node->width - i);
}

void	ft_s_argument(t_info *node)
{
	int		len;
	char	*str;

	str = va_arg(node->argument, char *);
	len = ft_strlen(str);
	if (str == NULL)
		str = "(null)";
	if (!node->period)
		width_s(node, str, len);
	else
		preci_s(node, str, len, 0);
}

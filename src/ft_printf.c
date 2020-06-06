/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:26:36 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:42:31 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_printf(const char *str, ...)
{
	t_info	node;
	int		len;
	int		i;

	i = 0;
	node.flag = '?';
	node.sign = 0;
	node.width = 0;
	node.period = 0;
	node.precision = 0;
	node.ret_value = 0;
	len = ft_strlen(str);
	va_start(node.argument, str);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i += ft_percentage(&node, str + i);
			while (str[i] == '%')
				i += ft_percentage(&node, str + i);
		}
		if (str[i] != '%' && str[i] != '\0')
		{
			pt_putchar(&node, str[i]);
		}
		i++;
	}
	
	// printf("\n");
	// printf("flag |%c| \n", node.flag);
	// printf("sign |%c| \n", node.sign);
	// printf("width|%d| \n", node.width);	
	// printf("dot? |%d| \n", node.period);
	// printf("preci|%d| \n", node.precision);
	// printf("conv |%c| \n", node.conversion);
	// printf("");

	va_end(node.argument);
	return (node.ret_value);
}

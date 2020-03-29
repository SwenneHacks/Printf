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
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	va_start(g_argument, str);
	init_globalv();
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i += ft_percentage(str + i);
		}
		if (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(g_argument);
	return (g_return);
}

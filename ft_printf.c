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

#include "printf.h"

int		ft_printf(const char *str, ...)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	va_start(g_ap, str);
	init_globalv();
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i += ft_checkpercent(str + i);
		}
		if (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(g_ap);
	return (g_return);
}

int		main(void)
{
	unsigned int	i = -7;
	char			c = 'a';
	char			*s = "Hi";

	ft_putchar('\n');
	printf("% d\n", i);
	ft_printf("% d\n", i);
	ft_putchar('\n');
	printf("%05d\n", i);
	ft_printf("%05d\n", i);
	ft_putchar('\n');
	printf("%c\n", c);
	ft_printf("%c\n", c);
	ft_putchar('\n');
	printf("%5s\n", s);
	ft_printf("%5s\n", s);
	ft_putchar('\n');
	printf("%-5s\n", s);
	ft_printf("%-5s\n", s);
	ft_putchar('\n');
	printf("%x\n", i);
	ft_printf("%x\n", i);
	ft_putchar('\n');
	return (0);
}

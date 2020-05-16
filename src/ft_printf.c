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
	int		j;

	i = 0;
	j = 0;
	g_return = 0;
	len = ft_strlen(str);
	va_start(g_argument, str);
	init_globalv();
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i += ft_percentage(str + i);
			while (str[i] == '%')
				i += ft_percentage(str + i);
		}
		if (str[i] != '%' && str[i] != '\0')
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	printf("\n");
	printf("flag |%c| \n", g_flag);
	printf("sign |%c| \n", g_sign);
	printf("width|%d| \n", g_width);	
	printf("dot? |%d| \n", g_period);
	printf("preci|%d| \n", g_precision);
	printf("conv |%c| \n", g_conversion);
	printf("");
	va_end(g_argument);
	return (g_return);
}

// int		main(void)
// {
// 	int a = 0;
// 	int b = 0;
// 	a = printf(		"[%d%d%d%d]\n", -1, -2, 3, 4);
// 	b = ft_printf(	"[%d%d%d%d]\n", -1, -2, 3, 4);
// 	printf("\npf |%d|\nft |%d|\n\n", a, b);
// 	return(0);
// }
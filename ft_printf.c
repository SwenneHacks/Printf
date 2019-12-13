/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/13 23:04:55 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



int 	main(void)
{
	char *s = "I like turtles";
	char c = 'o';
	int n = 78;
	int *p = &n;

    ft_printf("strc test: Hell%c %s!\n", c, s);
	printf("strc test: Hell%c %s!\n", c, s);
	ft_printf("Sign test: %d (signed) %u (unsigned)\n", n, n);
	printf("Sign test: %d (signed) %u (unsigned)\n", n, n);
	ft_printf("Hexa test: %X (base 16)\n", n);
	printf("Hexa test: %X (base 16)\n", n);
	ft_printf("Octa test: %o (base 8)\n", n);
	printf("Octa test: %o (base 8)\n", n);
	ft_printf("Pointer test: %p\n", p);
	printf("Pointer test: %p\n", p);
    return (0);
}

void 	ft_printf(char *str, ...)
{
	unsigned int 	index;
	va_list 		arg;

    index = 0;
    va_start(arg, str);
	while (str[index])
	{
		while (str[index] != '%' && str[index])
		{
			write(1, &str[index], 1);
			index++;
		}
		if (str[index])
		{
			ft_check_conversions(str + index, arg);
			index = index + 2;
		}
	}
	return ;
}

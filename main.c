/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:36:45 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/18 15:22:57 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	main(void)
{
	char *s = "I like turtles";
	char c = 'o';
	int n = 78;
	int *p = &n;

	ft_putstr("[String test]");
    ft_printf("	ft_: Hell%c %s!\n", c, s);
	printf("		pft: Hell%c %s!\n", c, s);
	ft_putstr("[Sign test]");
	ft_printf("	ft_: %d (signed) %u (unsigned)\n", n, n);
	printf("		pft: %d (signed) %u (unsigned)\n", n, n);
	ft_putstr("[Hexa test]");
	ft_printf("	ft_: %X (base 16)\n", n);
	printf("		pft: %X (base 16)\n", n);
	ft_putstr("[Octa test]");
	ft_printf("	ft_: %o (base 8)\n", n);
	printf("		pft: %o (base 8)\n", n);
	ft_putstr("[Pointer test]");
	ft_printf("	ft_: %p\n", p);
	printf("		pft: %p\n", p);
	
	ft_putstr("[Conversions OK]\n");

	ft_putstr("[Precision test]");
    //ft_printf();
	printf("		pft: Hell%.5c %s!\n", c, s);
	ft_putstr("[Left test]");
	//ft_printf();
	printf("		pft: %.0d (signed) %u (unsigned)\n", n, n);
	ft_putstr("[Zero test]");
	//ft_printf();
	printf("		pft: %0X (base 16)\n", n);
	ft_putstr("[Hashtag test]");
	//ft_printf();
	printf("		pft: %#o (base 8)\n", n);
	ft_putstr("[Star test]");
	//ft_printf();
	printf("		pft: %*p\n", p);
	
	ft_putstr("[Flags OK]\n");
	
    return (0);
}
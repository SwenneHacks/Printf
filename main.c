/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:36:45 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/19 17:47:07 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	main(void)
{
	char *s = "I like turtles";
	char c = 'o';
	int n = 42;
	int *p = &n;

	ft_putstr("			[Conversions]\n\n");

	ft_putstr("[String test]");
    ft_printf("		ft_: Hell%c %s!\n", c, s);
	printf("			pft: Hell%c %s!\n", c, s);
	ft_putstr("[Sign test]");
	ft_printf("		ft_: %d (signed) %u (unsigned)\n", n, n);
	printf("			pft: %d (signed) %u (unsigned)\n", n, n);
	ft_putstr("[Hexa test]");
	ft_printf("		ft_: %X (base 16)\n", n);
	printf("			pft: %X (base 16)\n", n);
	ft_putstr("[Octa test]");
	ft_printf("		ft_: %o (base 8)\n", n);
	printf("			pft: %o (base 8)\n", n);
	ft_putstr("[Pointer test]");
	ft_printf("		ft_: %p\n", p);
	printf("			pft: %p\n", p);
	
	ft_putstr("\n			[Flags]\n\n");

	ft_putstr("[Precision]");
    ft_printf("		_ft: %.01d \n", n);
	printf("			pft: %.01d \n", n);
	ft_putstr("[Precision.]");
    ft_printf("		_ft: %5.d \n", n);
	printf("			pft: %5.d \n", n);
	ft_putstr("[Precision0]");
    ft_printf("		_ft: %05.5d \n", n);
	printf("			pft: %05.5d \n", n);
	ft_putstr("[Left test]");
	ft_printf("		_ft: %-5d \n", n);
	printf("			pft: %-5d \n", n);
	ft_putstr("[Width test]");
	ft_printf("		_ft: %5d \n", n);
	printf("			pft: %5d \n", n);
	ft_putstr("[Zero test]");
	ft_printf("		_ft: %05d \n", n);
	printf("			pft: %05d \n", n);
	ft_putstr("[Sign test]");
	ft_printf("		_ft: %+5d \n", n);
	printf("			pft: %+5d \n", n);
	ft_putstr("[-Sign test]");
	ft_printf("		_ft: %+5d \n", n);
	printf("			pft: %+5d \n", n);
	ft_putstr("[Space test]");
	ft_printf("		_ft: % d \n", n);
	printf("			pft: % d \n", n);
	ft_putstr("Hashtag test]");
	ft_printf("		_ft: %#x \n", n);
	printf("			pft: %#x \n", n);
	ft_putstr("[Star test]");
	ft_printf("		_ft: %*d \n", 5, n);
	printf("			pft: %*d \n", 5, n);
	
	ft_putstr("[Flags OK]\n");
	
    return (0);
}
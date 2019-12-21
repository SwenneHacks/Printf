/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:36:45 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/21 18:39:57 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdio.h>

int 	main(void)
{
	char *s = "I like turtles";
	char c = 'o';
	int n = 42;
	int *p = &n;

	ft_putstr("				[String test]\n");
    ft_print("ft_: Hell%c %s!\n", c, s);
		printf("ptf: Hell%c %s!\n", c, s);
	ft_putstr("				[Sign test]\n");
	ft_print("ft_: %d (signed) %u (unsigned)\n", n, n);
		printf("ptf: %d (signed) %u (unsigned)\n", n, n);
	ft_putstr("				[Hexa test]\n");
	ft_print("ft_: %X (base 16)\n", n);
		printf("ptf: %X (base 16)\n", n);
	ft_putstr("				[Octa test]\n");
	ft_print("ft_: %o (base 8)\n", n);
		printf("ptf: %o (base 8)\n", n);
	ft_putstr("				[Pointer test]\n");
	ft_print("ft_: %p \n", p);
		printf("ptf: %p \n", p);
    return (0);
}
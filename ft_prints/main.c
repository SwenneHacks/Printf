/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:36:45 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/28 17:38:03 by swofferh      ########   odam.nl         */
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

	ft_putstr("[char test]\n");
	ft_prints("ft_: Hell%c!\n", c);
	printf("ptf: Hell%c!\n\n", c);
	ft_putstr("[spring test]\n");
	ft_prints("ft_: %% %s\n", s);
	printf("ptf: %% %s\n\n", s);
	ft_putstr("[sign test]\n");
	ft_prints("ft_: %d (signed) %u (unsigned)\n", n, n);
	printf("ptf: %d (signed) %u (unsigned)\n\n", n, n);
	ft_putstr("[hexa test]\n");
	ft_prints("ft_: %X (base 16)\n", n);
	printf("ptf: %X (base 16)\n\n", n);
	ft_putstr("[octa test]\n");
	ft_prints("ft_: %o (base 8)\n", n);
	printf("ptf: %o (base 8)\n\n", n);
	ft_putstr("[pointer test]\n");
	ft_prints("ft_: %p \n", p);
	printf("ptf: %p \n", p);
    return (0);
}
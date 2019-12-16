/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conversions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 13:55:41 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/16 20:26:31 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_conversions(char *str, va_list arg)
{
	char 			*s;
	int				i;
	unsigned int	u;
	unsigned long	h;
/*
**														STRING argument
*/
	if (str[1] == 's')//
	{
		s = va_arg(arg, char *);
		ft_putstr(s);
	}
/*
**														CHAR argument
*/
	if (str[1] == 'c')
	{
		i = va_arg(arg, int);			
		ft_putchar(i);
	}
/*
**														Decimal/Integer (base 10)
*/
	if (str[1] == 'd' || str[1] == 'i')
	{
		i = va_arg(arg, int);  			 
        ft_putnbr(i);
	}
/*
**														Unsigned int (decimal)
*/
	if (str[1] == 'u')
	{
		u = (unsigned int)va_arg(arg, unsigned int);  			 
        ft_putnbr(u);
	}
/*
**														Octa (base 8)
*/
	if (str[1] == 'o')
	{
		u = (unsigned int)va_arg(arg, unsigned int);  			 
        ft_putnbr_octa(u);
	}
/*
**														Pointer (adress)
*/
	if (str[1] == 'p')
	{
		h = (unsigned long)va_arg(arg, void *);
		ft_putstr("0x");
		ft_putnbr_hexa(h, 'x');
	}
/*
**														Hexa (base 16) lowercase
*/
	if (str[1] == 'x')
	{
		h = va_arg(arg, unsigned int);
		ft_putnbr_hexa(h, 'x');
	}
/*
**														Hexa (base 16) Uppercase
*/
	if (str[1] == 'X')
	{
		h = va_arg(arg, unsigned int);
		ft_putnbr_hexa(h, 'X');
		ft_toupper((int)h);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/21 18:35:32 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void 	ft_print(const char *str, ...)
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
			ft_conversions(str + index, arg);
			index = index + 2;
		}
	}
	return ;
}

void	ft_conversions(const char *str, va_list arg)
{
	char 			*s;
	int				i;
	unsigned int	u;
	unsigned long	h;

	if (str[1] == 's')
	{
		s = va_arg(arg, char *);
		ft_putstr(s);
	}
	if (str[1] == 'c')
	{
		i = va_arg(arg, int);			
		ft_putchar(i);
	}
	if (str[1] == 'd' || str[1] == 'i')
	{
		i = va_arg(arg, int);  			 
        ft_putnbr(i);
	}
	if (str[1] == 'u')
	{
		u = (unsigned int)va_arg(arg, unsigned int);
        ft_putnbr(u);
	}
	if (str[1] == 'o')
	{
		u = (unsigned int)va_arg(arg, unsigned int);  
        ft_putnbr_octa(u);
	}
	if (str[1] == 'p')
	{
		h = (unsigned long)va_arg(arg, void *);
		ft_putstr("0x");
		ft_putnbr_hexa(h, 'x');
	}
	if (str[1] == 'x')
	{
		h = va_arg(arg, unsigned int);
		ft_putnbr_hexa(h, 'x');
	}
	if (str[1] == 'X')
	{
		h = va_arg(arg, unsigned int);
		ft_putnbr_hexa(h, 'X');
		ft_toupper((int)h);
	}
}

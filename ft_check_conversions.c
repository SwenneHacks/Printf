/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 20:49:42 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/21 21:20:03 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_conversions(*thimo)
{
	if(thimo->conversion == 'c')
		&ft_convert_c;
	if(thimo->conversion == 's')
		&ft_convert_s;
	if(thimo->conversion == 'd')
		&ft_convert_d;
	if(thimo->conversion == 'i')
		&ft_convert_i;
	if(thimo->conversion == 'u')
		ft_convert_u;
	if(thimo->conversion == 'o')
		&ft_convert_o;
	if(thimo->conversion == 'p')
		&ft_convert_p;
	if(thimo->conversion == 'x')
		&ft_convert_x;
	if(thimo->conversion == 'X')
		&ft_convert_X;
}

int		ft_convert_c(t_info *info)
{
	char c;

	info->conv = 'c';
	c = (char)va_arg(info->arguments, int);
	return (ft_putchar(c));
}

int		ft_convert_s(t_info *info)
{
	char *s;

	s = NULL;
	info->conv = 's';
	s = va_arg(info->arguments, char *);
	if (s != NULL)
		s = ft_strdup(s);
	if (s == NULL)
		s = ft_strdup("(null)");
	s[info->len] = '\0';
	ft_putstr(s);
	free(s);
	return (0);
}

int		ft_convert_d(t_info *info)
{
	long	n;

	info->conv = 'd';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	n = (long long)va_arg(info->arguments, int);
	return (ft_putnbr(n));
}

int		ft_convert_i(t_info *info)
{
	long	n;

	info->conv = 'i';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	n = (long long)va_arg(info->arguments, int);
	return (ft_putnbr(n));
}

int		ft_convert_o(t_info *info)
{
	unsigned long n;

	info->conv = 'o';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	n = (unsigned int)va_arg(info->arguments, int);
	return (ft_putnbr_octa(n));
}

int		ft_convert_p(t_info *info)
{
	unsigned long	p;

	p = 0;
	info->conv = 'p';
	p = (unsigned long)va_arg(info->arguments, void *);
	ft_putstr("0x");
	ft_putnbr_hexa(p, 'x');
	return (0);
}

int		ft_convert_u(t_info *info)
{
	unsigned long	n;

	info->conv = 'u';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	u = (unsigned long long)va_arg(info->arguments, unsigned int);
	}
	return (ft_putnbr(u));
}

int			ft_convert_x(t_info *info)
{
	unsigned long n;

	info->conv = 'x';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	h = (unsigned int)va_arg(info->arguments, int);
	return (ft_putnbr_hexa(h, 'x'));
}

int			ft_convert_X(t_info *info)
{
	unsigned long n;

	info->conv = 'X';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	h = (unsigned int)va_arg(info->arguments, int);
	return (ft_putnbr_hexa(h, 'X'));
}
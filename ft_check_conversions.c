/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_conversions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 20:49:42 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/22 21:36:14 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_check_conversions(va_list arguments, t_list *info, char c)
{
	if(c == 'c')
		&ft_convert_c(arguments, info);
	else if(c == 's')
		&ft_convert_s(arguments, info);
	else if(c == 'd')
		&ft_convert_d(arguments, info);
	else if(c == 'i')
		&ft_convert_i(arguments, info)
	else if(c == 'u')
		ft_convert_u(arguments, info);
	else if(c == 'o')
		&ft_convert_o(arguments, info);
	else if(c == 'p')
		&ft_convert_p(arguments, info);
	else if(c == 'x')
		&ft_convert_x(arguments, info);
	else if(c == 'X')
		&ft_convert_X(arguments, info);
	return ;
}

t_conversions	ft_conversions(char c)
{
	static const t_conversions ascii[128] = {
		['c'] = &ft_convert_c,
		['s'] = &ft_convert_s,
		['d'] = &ft_convert_d,
		['i'] = &ft_convert_d,
		['u'] = &ft_convert_u,
		['o'] = &ft_convert_o,
		['p'] = &ft_convert_p,
		['X'] = &ft_convert_X,
		['x'] = &ft_convert_x,
	};
	return (ascii[c]);
}

int		ft_convert_c(va_list arguments, t_info *info)
{
	char c;

	info->conversion = 'c';
	c = (char)va_arg(info->arguments, int);
	return (ft_putchar(c));
}

int		ft_convert_s(t_info *info)
{
	char *s;

	s = NULL;
	info->conversion = 's';
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

	info->conversion = 'd';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	n = (long long)va_arg(info->arguments, int);
	return (ft_putnbr(n));
}

int		ft_convert_i(t_info *info)
{
	long	n;

	info->conversion = 'i';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	n = (long long)va_arg(info->arguments, int);
	return (ft_putnbr(n));
}

int		ft_convert_o(t_info *info)
{
	unsigned long n;

	info->conversion = 'o';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	n = (unsigned int)va_arg(info->arguments, int);
	return (ft_putnbr_octa(n));
}

int		ft_convert_p(t_info *info)
{
	unsigned long	p;

	p = 0;
	info->conversion = 'p';
	p = (unsigned long)va_arg(info->arguments, void *);
	ft_putstr("0x");
	ft_putnbr_hexa(p, 'x');
	return (0);
}

int		ft_convert_u(t_info *info)
{
	unsigned long	n;

	info->conversion = 'u';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	u = (unsigned long long)va_arg(info->arguments, unsigned int);
	return (ft_putnbr(u));
}

int		ft_convert_x(t_info *info)
{
	unsigned long h;

	info->conversion = 'x';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	h = (unsigned int)va_arg(info->arguments, int);
	return (ft_putnbr_hexa(h, 'x'));
}

int		ft_convert_X(t_info *info)
{
	unsigned long h;

	info->conversion = 'X';
	if (info->precision == 1 && (info->flags & e_zero) != 0)
		info->flags -= e_zero;
	h = (unsigned int)va_arg(info->arguments, int);
	return (ft_putnbr_hexa(h, 'X'));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/16 21:05:03 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_flags
{
	int				left;
	int				padzero;
	int				width;
	int				precision; //minimum amount of chars to print (in case of numbers if fills the rest with zeros)
	int				numlen;
	int				size;
	char			type;
	int				len;
	char			neg;
	int				count;
	unsigned int	u_numlen;
}					t_flags;

void 				ft_printf(char *,...);
void				ft_check_conversions(char *str, va_list arg);
/*
** Extra functions (outside libft)
*/
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
int					ft_toupper(int n);
int					ft_tolower(int n);
void				ft_putnbr_octa(unsigned long n);
void				ft_putnbr_hexa(unsigned long n, char c);

#endif

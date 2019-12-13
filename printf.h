/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/13 15:32:00 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

void 	ft_printf(char *,...);
void	ft_check_conversions(char *str, va_list arg);

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
int		ft_toupper(int n);
int		ft_tolower(int n);

void	ft_putnbr_base(unsigned long n, int base, char c);

#endif

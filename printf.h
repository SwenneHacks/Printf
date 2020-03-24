/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:27:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 22:37:42 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define NOFLAG 0
# define MINUS -1
# define ZERO 1

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

va_list	g_argument;
int		g_return;
int		g_flag;
int		g_period;
int		g_minfield;
int		g_maxfield;
char	g_conversion;

int		ft_vabs(int nbr);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_lenbase(long long nbr, int base);
void	ft_puthexa(unsigned long n, char c);
void	ft_putocta(unsigned long n);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putlen(char c, int len);
int		ft_isdigit_signed(int c);
/*
**      My printf Functions
*/
int		ft_printf(const char *str, ...);
int		ft_percentage(const char *str);
int		ft_flags(const char *str);
void	ft_c_argument(void);
void	ft_s_argument(void);
void	ft_d_argument(void);
void	ft_x_argument(void);
void	init_globalv(void);
int		ft_maxfield(const char *str);
int		ft_precision(const char *str);
int		ft_conversion(char g_argument);
int		ft_minfield(const char *str);
int		ft_argument(const char *str);
int		ft_after_percent(const char *str);

#endif

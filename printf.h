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

# define MINUS '-'
# define SPACE ' '
# define ZERO 'O'
# define NOFLAG '0'

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

va_list	g_argument;
int		g_return;
char	g_flag;
int		g_period;
int		g_width;
int		g_precision;
char	g_conversion;

int		ft_sign(int nbr);
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
int		ft_after_percent(const char *str);
int		ft_flags(const char *str);
void	init_globalv(void);
int		ft_width(const char *str);
int		ft_precision(const char *str);
int		ft_asterik(const char *str);
int		ft_conversion(char g_argument);
int		ft_argument(const char *str);
void	ft_c_argument(void);
void	ft_s_argument(void);
void	ft_d_argument(void);
void	ft_x_argument(void);
void	ft_p_argument(void);
void	ft_u_argument(void);

#endif

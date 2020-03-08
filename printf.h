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

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

va_list	g_ap;
int		g_return;
int		g_flag;
int		g_minfield;
int		g_period;
int		g_maxfield;
char	g_argument;

int		ft_vabs(int nbr);
int		ft_atoi(const char *str);
int		ft_isdigit_signed(int c);
size_t	ft_strlen(const char *str);
void	init_globalv(void);
int		ft_calcnbr(int nbr, unsigned long binf, unsigned long bsup);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_putchar_while(char c, int i);
void	ft_c_argument(void);
void	ft_s_argument(void);
void	ft_d_argument(void);
int		ft_checkpercent(const char *str);
int		ft_printf(const char *str, ...);
int		ft_checkflags(const char *str);
int		ft_checkmaxfield(const char *str);
int		ft_checkperiod_maxfield(const char *str);
int		ft_go_to_argument(char g_argument);
int		ft_checkminfield(const char *str);
int		ft_checkargument(const char *str);
int		ft_check_after_percent(const char *str);

#endif

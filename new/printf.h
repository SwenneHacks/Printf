/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 20:56:58 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define TRUE 1
# define FALSE 0

# include "libft/libft.h"
# include <stdarg.h>

/*
** 	Testing inclusions
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** global variables. Easypeasy.
*/

va_list		g_arguments;
int			g_return;
int			g_flag;
int			g_minfield;
int			g_maxfield;
char		g_argument;
int			g_dot;

void		ft_printf(const char *str, ...);
void		init_globalv(void);
int			ft_calcul_nbr(int nbr, unsigned long binf, unsigned long bsup);
void		ft_c_argument(void);
void		ft_s_argument(void);
void		ft_d_argument(void);
void		ft_x_argument(void);
int			ft_checkpercent(const char *format);
int			ft_checkflags(const char *format);
int			ft_checkmaxfield(const char *format);
int			ft_checkperiod_maxfield(const char *format);
int			ft_go_to_argument(char g_argument);
int			ft_checkminfield(const char *format);
int			ft_checkargument(const char *format);
int			ft_check_after_percent(const char *format);

/*
** 					Libft functions
*/
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
/*
** 					Extra functions (outside libft)
*/
void		ft_putnbr(int n);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putendl(char *s);
int			ft_toupper(int n);
int			ft_tolower(int n);
int			ft_negative(int nbr);
int			ft_isdigit_signed(int c);
int			ft_putwhile(char c, int i);
void		ft_putnbr_octa(unsigned long n);
void		ft_putnbr_hexa(unsigned long n, char c);
size_t		ft_nbrlenbase(long long nbr, int base);

#endif

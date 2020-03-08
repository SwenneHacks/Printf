/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 18:48:05 by swofferh      ########   odam.nl         */
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
**	enumerations for the flags and modifiers stored in flags.
**	these are written down here as bitshifts, but in essence the exact number
**	linked to an enum is not relevant, just that we can uniquely store and
**	fetch any option (flag or modifier)
*/
enum				e_flags
{
	PLUS = 1 << 0,
	LEFT = 1 << 1,
	HASH = 1 << 2,
	ZERO = 1 << 3,
	STAR = 1 << 4,
	SPACE = 1 << 5,
	MIDDLE = 1 << 6
};

/*
** global variables. Easypeasy.
*/

va_list		g_arguments;
int			g_return_value;
int			g_flags;
int			g_minfield;
int			g_maxfield;
char		g_argument;
int			g_dot;

/*
** this info struct contains anything that we might need to print.
*/

typedef struct		s_info
{
	int				width;
	int				precision;
	int				total;
	int				padding;
	char			conversion;
	e_flags			flags;
	char			precitype;
	va_list			arguments;
}					t_info;

void				ft_printf(const char *str, ...);
int					ft_flags(const char *str, t_thimo *info);
void				ft_conve(const char *str, va_list arg);
void				ft_find_flags(const char str, t_thimo info, int i);
void				ft_find_width(const char str, t_thimo info, int i);
void				ft_find_preci(const char str, t_thimo info, int i);
int					ft_percentage(const char *str, t_info *info);
char				ft_conversions(const char *str, t_info *info);
int					ft_check_flags(const char *str, t_info *info);
int					ft_find_flags(const char *str, t_info *info, int i);
int					ft_find_width(const char *str, t_info *info, int i);
int					ft_find_precision(const char *str, t_info *info, int i);
/*
** 					Libft functions
*/
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
/*
** 					Extra functions (outside libft)
*/
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
int					ft_toupper(int n);
int					ft_tolower(int n);
void				ft_putnbr_octa(unsigned long n);
void				ft_putnbr_hexa(unsigned long n, char c);
size_t				ft_nbrlenbase(long long nbr, int base);

#endif

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

# define NOFLAG 'o'
# define SPACE ' '
# define MINUS '-'
# define HASH '#'
# define PLUS '+'
# define ZERO '0'

# define TRUE 1
# define FALSE 0
# define INT_MIN -2147483648
# define INT_MAX 2147483648

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"

typedef struct s_info
{
    char		flag;
    int			sign;
	int			width;
	int			period;
	int			precision;
	char		conversion;
	int			ret_value;
    va_list		argument;
} 				t_info;

int		ft_sign(int nbr);
int     ft_maxof(int v1, int v2);
int		ft_isdigit_signed(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_lenbase(long long nbr, int base);
/*
**      Adapted libft Functions:
*/
void	pt_puthexa(t_info *node, unsigned int n, char c);
void	pt_putocta(t_info *node, unsigned long n);
void	pt_putnbr(t_info *node, int n);
void	pt_putstr(t_info *node, char *str);
int		pt_putlen(t_info *node, char c, int len);
void	pt_putchar(t_info *node, char c);
int 	pt_putsign(t_info *node, int nbr);
/*
**      My printf Functions:
*/
int		ft_printf(const char *str, ...);
int		ft_percentage(t_info *node, const char *str);
int		ft_after_percent(t_info *node, const char *str);
int		ft_flags(t_info *node, const char *str);
int		ft_width(t_info *node, const char *str);
int		ft_asterik(t_info *node, const char *str);
int		ft_argument(t_info *node, const char *str);
int		ft_precision(t_info *node, const char *str);
int		ft_conversion(t_info *node, char conversion);
/*
**      Arguments / conversions:
*/
void	ft_no_argument(t_info *node);
void	ft_c_argument(t_info *node);
void	ft_s_argument(t_info *node);
void	ft_d_argument(t_info *node);
void	ft_x_argument(t_info *node);
void	ft_p_argument(t_info *node);
void	ft_u_argument(t_info *node);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/18 15:28:01 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

enum				e_flags
{
	e_plus = 1 << 0,
	e_left = 1 << 1,
	e_hash = 1 << 2,
	e_zero = 1 << 3,
	e_space = 1 << 4,
	e_middle = 1 << 5
};

typedef struct		s_info
{
	va_list			arguments; 	//Va_list with all the arguments that printf received.
	unsigned char	conversion; //Contains the char representing the conversion specifier.
	unsigned char	flags; 		//Uses the above mentioned enums to store flags.
	unsigned long	u_numlen; 	//Adds up the total amount of characters printed as a return value.
	int				precision;	//Positive if a precision was found, negative if it was not.
	int				width;		//Simple value representing the width provided.
	char			type;		//Type of precision provided
	int				size;		//Size of precision
	int				sign;		//Used to specify if a number is positive or negative.
}					t_info;

void 				ft_printf(const char *, ...);
void				ft_check_conversions(const char *str, va_list arg);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/21 21:16:24 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
/*
** 	Testing inclusions
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
/*
**	enumerations for the flags and modifiers stored in lenmod and flags.
**	these are written down here as bitshifts, but in essence the exact number
**	linked to an enum is not relevant, just that we can uniquely store and
**	fetch any option (flag or modifier)
*/
enum				e_flags 
{
	e_plus = 1 << 0,
	e_left = 1 << 1,
	e_hash = 1 << 2,
	e_zero = 1 << 3,
	e_space = 1 << 4,
	e_middle = 1 << 5
};
/*
**					this info struct contains anything that we might need to print.
*/
typedef struct		s_info
{
	va_list			arg; 	//Va_list with all the arguments that printf received.
	unsigned char	conv; 	//Contains the char representing the conversion specifier.
	unsigned char	flags; 	//Uses the above mentioned enums to store flags.
	unsigned long	length;	//Adds up total amount of characters as a return value.
	int				preci;	//Positive if a precision was found, negative if it not.
	int				width;	//Simple value representing the width provided.
	char			type;	//Type of precision provided
	int				size;	//Size of precision
	int				sign;	//Used to specify if a number is positive or negative.
}					t_info;

typedef struct		s_thimo
{
	int 			width;
	int 			pres;
	int				count;
	int 			padding;
	char 			conversion;
}					t_thimo;

void 				ft_printf(const char *, ...);
int					ft_percentage(const char *str, t_info *info);
char				ft_conversions(const char conversion);
int					ft_flags(const char *str, t_info *info);
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

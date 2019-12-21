/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/21 18:16:40 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

void 				ft_print(const char *str, ...);
void				ft_conversions(const char *str, va_list arg);
/*
** 					Libft functions
*/
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
** 					Extra functions (outside libft)
*/
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
int					ft_isupper(int n);
int					ft_islower(int n);
void				ft_putnbr_octa(unsigned long n);
void				ft_putnbr_hexa(unsigned long n, char c);
size_t				ft_nbrlen_base(long long nbr, int base);

#endif

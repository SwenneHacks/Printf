/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/28 17:15:49 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdarg.h>

void				ft_prints(const char *str, ...);
void				ft_printf(const char *str, ...);
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

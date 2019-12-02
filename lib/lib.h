/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 20:54:15 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <unistd.h>
# include <stdlib.h>

//printf
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
char	*ft_strrev(char *s);
void 	reverse(char *str, int len);
char 	*convert(unsigned int num, int base);
char 	*itoa_base(int num, char* str, int base);

#endif

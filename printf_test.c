/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 20:49:27 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

/*
** MAN STDARG
** A function may be called with a varying number of arguments of varying types.
** The include file <stdarg.h> declares a type (va_list) and defines three
** macros for stepping through a list of arguments whose number and types are
** not known to the called function. The va_arg() macro expands to an expression
** that has the type and value of the next argument in the call.
** #define 
*/

void 	ft_printf(char *,...);
void	ft_found_percentage(char *str, va_list arg);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
size_t	ft_strlen(const char *s);

int 	main(void)
{
	//char str[] = "I like turtles";
	char c = 'o';
	
    ft_printf(" %c", c);
    return (0);
}

void 	ft_printf(char *str, ...)
{
   
	unsigned int 	index;
	va_list 		arg;

    index = 0;
    va_start(arg, str);
	while (str[index])
	{
		while (str[index] != '%')
		{
			ft_putchar(str[index]);
			index++;
		}
		ft_found_percentage(str + index, arg);
		return ;
	}
}

void	ft_found_percentage(char *str, va_list arg)
{
	char 	*s;
	int		index;
	
	if (str[1] == 's')
	{
		s = va_arg(arg, char *);	//variable: STRING argument
        ft_putendl(s);
	}
	
	if (str[1] == 'c')
	{
		index = va_arg(arg, int);	//Variable: CHAR argument
		ft_putchar(index);
		ft_putchar('\n');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

size_t	ft_strlen(const char *s)
{
	int index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

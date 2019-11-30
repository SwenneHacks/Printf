/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_printf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/30 23:23:49 by swofferh      ########   odam.nl         */
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

void ft_printf(char *,...);
char* convert(unsigned int, int);

int main(void)
{
	char str[] = "I like turtles";
	//char c = 's';
	
    ft_printf("%s", str);
    return 0;
}

/*
** Before implementation of printf( ) function we have to deal with an unusual
** problem which is variable arguments. As we knowit already, printf takes many
** arguments besides strings so we have to use a std library called stdarg.h
** to handle this problem (variable arguments). In this implementation context,
** we don’t need learn all about this library because we can use some macro
** functions which are understandable when used by our C program.
*/

//framework from stack overflow

void	ft_found_percentage(char *str, va_list arg)
{
	char 	*s;
	int		index;
	
	if ((str)[0] == 's')
	{
		s = va_arg(arg, char *);	//variable: STRING argument
        ft_putendl(s);
	}
	(*str)++;
	
	if ((str)[0] == 'c')
	{
		index = va_arg(arg, int);	//Variable: CHAR argument
			ft_putchar(index);
	}
	(*str)++;
}

void 	ft_printf(char *str, ...)
{
   
	unsigned int 	index;
	va_list 		arg;

    
    index = 0;
    va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_found_percentage(str, arg);
		}
		ft_putchar(str[0]);
		if (str[-1] != '%')
			str++;
	}
}

/*    FRAMEWORK NSPIRATION

void 	ft_printf(char *format, ...)
{
	//char 			*s;
	//char 			*str;
											
    while((str = format) && (*str != '\0'))		//Module 1: Initializing ft_printf's arguments 
    {
        //Scaning for usual printf() variables
		while(str[index] != '\0')
        {
            ft_putchar(*str);
            str++;
		}
	}

    if (str[index] == '%') 					//Module 2: Fetching and executing arguments
    { 
        while (str[index + 1] == 'c')
		{
			index = va_arg(arg, int);      		    //Variable: CHAR argument
			ft_putchar(index);
            break ;
		}

		while (str[index + 1] == 's')
		{
			s = va_arg(arg, char *);       			//variable: STRING argument
            ft_putendl(s);
            break ;
		}
		
		while (str[index + 1] == 'd')
		{
			index = va_arg(arg, int);        	   //Variable: Decimal/Integer
           ft_putnbr(index);
		}

		while (str[index + 1] == 'p')			//Variable: Pointer, Adress
		{
			index = va_arg(arg, long int);
			ft_putendl(&index);
		}
       
		while (str[index + 1] == 'o')
		{
			index = va_arg(arg, unsigned int);   	 //Variable: Octal representation
            ft_putendl(convert(index, 8));
            break ;
		} 
		
		while (str[index + 1] == 'x')
		{
			index = va_arg(arg, unsigned int);   	 //Variable: Hexadecimal argument
            ft_putendl(convert(index, 16));
            break ;
        } 
    }							
    va_end(arg);					//Module 3: Closing argument list to necessary clean-up
}	

char *convert(unsigned int num, int base)	//Convert an integer number into octal, hex, etc.
{
    static char *representation;
    static char buffer[50];
    char *ptr;

    representation = "0123456789ABCDEF";
	ptr = &buffer[49];
    *ptr = '\0';

    while(num != 0)
    {
        *--ptr = representation[num%base]; 
        num /= base; 
    }
    return(ptr); 
}

*/

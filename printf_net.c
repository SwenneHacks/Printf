/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_net.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:45:49 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 20:51:53 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//   FRAMEWORK NSPIRATION

#include <stdio.h>
#include <stdarg.h>

void 	ft_printf(char *,...);
char	*convert(unsigned int, int);

int 	main(void)
{
	char str[] = "I like turtles";
	
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

void 	net_printf(char *format, ...)
{
	char 			*s;
	char 			*str;
	unsigned int 	index;
	
	va_list 		arg;
	va_start(arg, format);
										
    while((str = format) && (*str != '\0'))		//Module 1: Initializing ft_printf's arguments 
    {
		while(*str != '\0')						//Scaning for usual printf() variables
        {
            putchar(*str);
            str++;
		}
		str++;
	
    while (str[index] == '%') 					//Module 2: Fetching and executing arguments
    { 
		index++;
        if (str[1] == 'c')
		{
			index = va_arg(arg, int);      		//Variable: CHAR argument
			putchar(index);
            break ;
		}

		if (str[1] == 's')
		{
			s = va_arg(arg, char *);       		//variable: STRING argument
            puts(s);
            break ;
		}
		
		if (str[1] == 'd')
		{
			index = va_arg(arg, int);          	//Variable: Decimal/Integer (base 10)
           	putchar(index);
		}

		if (str[1] == 'p')				//Variable: Pointer, Adress
		{
			index = va_arg(arg, long int);
			puts(&index);
		}
       
		if (str[1] == 'o')
		{
			index = va_arg(arg, unsigned int);  //Variable: Octal representation
            puts(convert(index, 8));
            break ;
		} 
		
		if (str[1] == 'x')
		{
			index = va_arg(arg, unsigned int);   	 //Variable: Hexadecimal argument
            puts(convert(index, 16));
            break ;
        } 
    }							
    va_end(arg);					//Module 3: Closing argument list to necessary clean-up
}

//Convert an integer number into octal, hex, etc.
// char 	*convert(unsigned int num, int base)
// {
//     static char *representation;
//     static char buffer[50];
//     char *ptr;

//     representation = "0123456789ABCDEF";
// 	ptr = &buffer[49];
//     *ptr = '\0';

//     while(num != 0)
//     {
//         *--ptr = representation[num%base]; 
//         num /= base; 
//     }
//     return (ptr); 
// }

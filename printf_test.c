/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/03 20:23:20 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "lib.h"

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
char 	*ft_strrev(char *str);
size_t	ft_strlen(const char *s);
void 	ft_printf(char *,...);
void	ft_found_percentage(char *str, va_list arg);
char	*ft_itoa_base(int nbr, char *str, int base);

/*
** MAN STDARG
** A function may be called with a varying number of arguments of varying types.
** The include file <stdarg.h> declares a type (va_list) and defines three
** macros for stepping through a list of arguments whose number and types are
** not known to the called function. The va_arg() macro expands to an expression
** that has the type and value of the next argument in the call.
** #define 
*/

int 	main(void)
{
	char s[] = "I like Niki";
	char c = 'o';
	char h = 'S';
	int n = 2;
	
    ft_printf("Hell%c %s! %c%d", c, s, h, n);
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
		while (str[index] != '%' && str[index])
		{
			write(1, &str[index], 1);
			index++;
		}
		if (str[index])
		{
			ft_found_percentage(str + index, arg);
			index = index + 2;
		}
	}
	ft_putchar('\n');
	return ;
}

// void	ft_found_backslach(char *str)
// {
// 	if (str[0] == '\')
// 		ft_putchar(str[1]);
// 		str++; 
// }

void	ft_found_percentage(char *str, va_list arg)
{
	char 	*s;
	int		i;
	
	// WIDTH OPTION
	//if (ft_isdigit(str[1])
	
	if (str[1] == 's')
	{
		s = va_arg(arg, char *);	//variable: STRING argument
		write(1, s, ft_strlen(s));
	}
	
	if (str[1] == 'c')
	{
		i = va_arg(arg, int);		//Variable: CHAR argument
		ft_putchar(i);
	}

	if (str[1] == 'd' || str[1] == 'i')
	{
		i = va_arg(arg, int);  		 //Variable: Decimal/Integer (base 10)
        ft_putnbr(i);
	}
}

// char 	*ft_itoa_base(int nbr, char *str, int base) 
// {
//     int i = 0;
//     int isNegative = 1;
// 	int convert;

//     while (nbr == 0)
//     {
//         str[i] = '0';
// 		i++;
//         str[i] = '\0';
//         return (str);
//     }
//     if (nbr < 0 && base == 10)
//     {
//         isNegative = 0;
//         nbr = -nbr;
// 	}
//     while (nbr != 0)
//     {
//         convert = nbr % base; 
//         str[i++] = (convert > 9)? (convert - 10) + 'a' : convert + '0'; 
//         nbr = nbr/base; 
//     }
//     while (isNegative)
// 	{
// 		str[i] = '-';
// 		i++;
// 	}
//     str[i] = '\0';
//     ft_strrev(str);
//     return (str);
// }

//Reverse string
char	*ft_strrev(char *str)
{
	char	rev;
	int		len;
	int		index;

	len = ft_strlen(str);
	index = 0;
	while (index < len / 2)
	{
		rev = str[index];
		str[index] = str[len - index - 1];
		str[len - index - 1] = rev;
		index++;
	}
	return (str);
}


size_t	ft_strlen(const char *s)
{
	int index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
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

// function to convert decimal to octal 
void dec_to_octal(int n)
{
    // array to store octal number
    int octalNum[100];

    // counter for octal number array
    int i = 0;
    while (n != 0) 
	{
        // storing remainder in octal array 
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
	i = 1;
	while(i < n + 1) 
	{
    	// your current loop body goes here
    	i++;
	}
}

// Driver program to test above function 
int main() 
{
    int n = 33;

    decToOctal(n);

    return 0;
} 

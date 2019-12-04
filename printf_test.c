/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/04 20:28:31 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
int		ft_toupper(int n);
int		ft_tolower(int n);
char 	*ft_strrev(char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(int n, int base);
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
	char s[] = "I like turtles";
	char c = 'o';
	int n = 65;
	char *ptr;
	
    ft_printf("String test: Hell%c %s! %c%d\n", c, s);
	ft_printf("String test: Hell%c %s! %c%d\n", c, s);
	ft_printf("Hexa test: %d(base 10) %x(base 16)\n", n, n);
	printf("Hexa test: %d(base 10) %x(base 16)\n", n, n);
	printf("%p", &ptr);
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
	return ;
}

// void	ft_found_backslach(char *str)
// {
// 	if (str[0] == '\\')
// 	{
// 		ft_putchar(str[1]);
// 		str++;
// 	}
// }

void	ft_found_percentage(char *str, va_list arg)
{
	char 	*s;
	int		i;
	
	//variable: STRING argument
	if (str[1] == 's')
	{
		s = va_arg(arg, char *);		
		ft_putstr(s);
	}
	
	//Variable: CHAR argument
	if (str[1] == 'c')
	{
		i = va_arg(arg, int);			
		ft_putchar(i);
	}
	
	//Variable: Decimal/Integer (base 10)
	if (str[1] == 'd' || str[1] == 'i')
	{
		i = va_arg(arg, int);  			 
        ft_putnbr_base(i, 10);
	}
	
	//Variable: Hexadecimal (base 16) + lowercase
	if (str[1] == 'x')
	{
		i = va_arg(arg, unsigned int);
		ft_putnbr_base(i, 16);
		ft_tolower(i);
	}
	
	//Variable: Hexadecimal (base 16) + Uppercase
	if (str[1] == 'X')
	{
		i = va_arg(arg, unsigned int);
		ft_putnbr_base(i, 16);
		ft_toupper(i);
	}
	
	// Variable: Pointer (adress)
	// if (str[1] == 'p')
	// {
	// 	i = va_arg(arg, void *);
	// 	ft_putnbr_base( (unsigned long )i, 16);
	// }

	// // WIDTH OPTION
	// if (ft_isdigit(str[1]) == 0)
	// {
	// 	return (ft_found_flag ())
	// }
}

size_t	ft_strlen(const char *s)
{
	int index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

void	ft_putnbr_base(int n, int base)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-n, base);
	}
	else if (n > 9)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
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

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 18:00:18 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/09 16:37:20 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
int		ft_toupper(int n);
int		ft_tolower(int n);
char 	*ft_strrev(char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(unsigned long n, int base, char c);
void	ft_found_percentage(char *str, va_list arg);
char	*ft_itor_hexa(int n, int base, char c);
void 	ft_printf(char *,...);

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
	char *s = "I like turtles";
	char c = 'o';
	int n = -78;
	int *p = &n;
	
    ft_printf("strc test: Hell%c %s!\n", c, s);
	printf("strc test: Hell%c %s!\n", c, s);
	ft_printf("Sign test: %d (signed) %u (unsigned)\n", n, n);
	printf("Sign test: %d (signed) %u (unsigned)\n", n, n);
	ft_printf("Hexa test: %X (base 16)\n", n);
	printf("Hexa test: %X (base 16)\n", n);
	ft_printf("Octa test: %o (base 8)\n", n);
	printf("Octa test: %o (base 8)\n", n);
	ft_printf("Pointer test: %p\n", p);
	printf("Pointer test: %p\n", p);
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

void	ft_found_percentage(char *str, va_list arg)
{
	char 			*s;
	int				i;
	unsigned int	u;
	unsigned long	h;
	
	if (str[1] == 's')							//Var: STRING argument
	{
		s = va_arg(arg, char *);		
		ft_putstr(s);
	}
	if (str[1] == 'c')							//Var: CHAR argument
	{
		i = va_arg(arg, int);			
		ft_putchar(i);
	}		
	if (str[1] == 'd' || str[1] == 'i')			//Var: Decimal/Integer (base 10)
	{
		i = va_arg(arg, int);  			 
        ft_putnbr(i);
	}
	if (str[1] == 'u')							//Var: Unsigned int (decimal)
	{
		u = (unsigned int)va_arg(arg, unsigned int);  			 
        ft_putnbr_base(u, 10, 'u');
	}
	if (str[1] == 'o')							//Var: Unsigned int (octal)
	{
		u = (unsigned int)va_arg(arg, unsigned int);  			 
        ft_putnbr_base(u, 8, 'o');
	}
	if (str[1] == 'p')							//Var: Pointer (adress)
	{
		h = (unsigned long)va_arg(arg, void *);
		ft_putstr("0x");
		ft_putnbr_base(h, 16, 'x');
	}
	if (str[1] == 'x')							//Var: Hexadecimal (base 16) + lowercase
	{
		h = va_arg(arg, unsigned int);
		ft_putnbr_base(h, 16, 'x');
	}
	if (str[1] == 'X')							//Var: Hexadecimal (base 16) + Uppercase
	{
		h = va_arg(arg, unsigned int);
		ft_putnbr_base(h, 16, 'X');
		ft_toupper((int)h);
	}
	// if (ft_isdigit(str[1]) == 0)
	// {
	// 	return (ft_found_flag ());
	// }
	// if (str[1] == '+')
	// {
	// 	i = va_arg(arg, int);
	// 	if (i > 0)
	// 		ft_putchar('+');
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
		ft_putchar(n % 10 + '0');
	return ;
}

void	ft_putnbr_base(unsigned long n, int base, char c)
{
	if (n > 15)
	{
		ft_putnbr_base(n / base, base, c);
		ft_putnbr_base(n % base, base, c);
	}
	else if (n > 9 && c == 'x')
		ft_putchar(n + 87);
	else if (n > 9 && c == 'X')
		ft_putchar(n + 55);
	else
		ft_putchar(n % base + '0');
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

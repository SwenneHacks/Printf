#include "printf.h"
#include <stdio.h>
#include <limits.h>


void pt_putchar(const char c)
{
    write(1, &c, 1);
    g_return++;
}

void	pt_putnbr(int n, int base)
{
	if (n < 0)
	{
		pt_putchar('-');
		pt_putnbr(-n, base);
	}
	else if (n > base)
	{
		pt_putnbr(n / base, base);
		pt_putnbr(n % base, base);
	}
	else
	{
		pt_putchar(n + '0');
	}
}

int ft_strlen(const char *str)
{
    int i;
    i = 0;

    while(str[i])
        i++;
    return(i);
}

int ft_atoi(const char *str)
{
    int i;
    int n;
    int r;

    r = 0;
    n = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            n = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - '0');
        i++;
    }
    return (n * r);
}

int ft_conversion_d(void)
{
    int	arg;

	arg = va_arg(g_argument, int);
	pt_putnbr(arg, 10);
    return(1);
}

int ft_conversion_x(void)
{
    int	arg;

	arg = va_arg(g_argument, unsigned int);
	pt_putnbr(arg, 16);
    return(1);
}

int ft_conversion_s(void)
{
    int	i;
    char *arg;

    i = 0;
	arg = va_arg(g_argument, char *);
    while(arg[i])
    {
        pt_putchar(arg[i]);
        i++;
    }
    return(1);
}

int ft_argument(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'd')
            i += ft_conversion_d();
        else if (str[i] == 's')
            i += ft_conversion_s();
        else if (str[i] == 'x')
            i += ft_conversion_x();
        else
            pt_putchar(str[i]);
    }
    return (i);
}

int	ft_percentage(const char *str)
{
    int i;
	int duo;

	i = 0;
	while (str[i] == '%')
		i++;
	duo = i / 2;
	while (duo)
	{
        pt_putchar('%');
		duo--;
	}
	if (i % 2 == 1)
        //pt_putchar('Y');
		i += ft_argument(str + i);
	return (i);
}

int	ft_printf(const char *str, ...)
{
    int len;
    int i;

    i = 0;
    g_return = 0;
    len = ft_strlen(str);
    va_start(g_argument, str);
    while (str[i] && i < len)
    {
        if (str[i] == '%' && str[i] != '\0')
            i += ft_percentage(str + i);
        if (str[i] != '%' && str[i] != '\0')
            pt_putchar(str[i]);
        i++;
    }
    va_end(g_argument);
	return (g_return);
}

int main()
{
    printf(" Ret=%d %%%%%%", ft_printf("Test\n=> %d, %x, %s, %%, %%%%%%", 1, 2, "03"));
}

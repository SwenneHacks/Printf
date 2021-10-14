#include "printf.h"
#include <stdio.h>
#include <limits.h>

int ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i])
        i++;
    return(i);
}

int ft_atoi(char *str)
{
    int i;
    int n;
    int r;

    r = 0;
    n = 1;
    i = 0;
    while (str[i] == ' ', str[i] == '\t', str[i] == '\r', str[i] == '\v', str[i] == '\f', str[i] == '\n')
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
    return (n * r)
}

int	ft_printf(const char *str, ...)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(str);
    va_start(g_argument, str);
    while (str[i] && i < len)
    {
        
    }
}

int main()
{
    printf("Ret=%d", ft_printf("Test\n %d, %x, %s", 1, 2, "3"));
}
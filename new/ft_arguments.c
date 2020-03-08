/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arguments.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 19:13:51 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/08 19:40:59 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_argument(void)
{
	char	c;

	c = va_arg(g_ap, int);
	if (g_flag == -1 && !g_minfield)
		ft_putchar(c);
	if ((g_minfield != 1 && g_flag == 1))
	{
		ft_putchar(c);
		ft_putchar_while(' ', (ft_vabs(g_minfield) - 1));
	}
	else if (g_flag == -1 && g_minfield > 0)
	{
		ft_putchar_while(' ', g_minfield - 1);
		ft_putchar(c);
	}
}

void    ft_no_dot(int nbr, int char_nbr)
{
	if (!g_minfield)
		ft_putnbr(nbr);
	else if (g_flag == 1 && g_minfield != 0)
	{
		ft_putnbr(nbr);
		ft_putchar_while(' ', ft_vabs(g_minfield) - char_nbr);
	}
	else if (!g_flag && g_minfield > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		ft_putchar_while('0', g_minfield - char_nbr);
		ft_putnbr(nbr);
	}
	else if (g_flag == -1 && g_minfield > 0)
	{
		ft_putchar_while(' ', g_minfield - char_nbr);
		ft_putnbr(nbr);
	}
}

void	ft_s_argument_noperiod(char *str)
{
	int	lenstr;

	lenstr = ft_strlen(str);
	if (lenstr > g_minfield)
		ft_putstr(str);
	else
	{
		if (g_flag == 1 && g_minfield > 0)
		{
			ft_putstr(str);
			ft_putchar_while(' ', g_minfield - lenstr);
		}
		else if (!g_minfield)
			ft_putstr(str);
		else if (g_flag == -1 && g_minfield > 0)
		{
			ft_putchar_while(' ', g_minfield - lenstr);
			ft_putstr(str);
		}
	}
}

int     ft_nb_str(char *str)
{
	int	len_str;

	len_str = ft_strlen(str);
	if (len_str <= g_maxfield)
		return (len_str);
	else
		return (g_maxfield);
}

void	ft_s_argument_period(char *str)
{
	int i;
	int	nb_str;

	i = 0;
	if (g_flag == 1)
	{
		while (i < g_maxfield && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		ft_putchar_while(' ', g_minfield - i);
	}
	else if (!g_minfield)
	{
		while (i < g_maxfield && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		nb_str = ft_nb_str(str);
		ft_putchar_while(' ', g_minfield - nb_str);
		while (i < nb_str && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_s_argument(void)
{
	char *str;

	str = va_arg(g_ap, char *);
	if (str == NULL)
		str = "(null)";
	if (!g_dot)
		ft_s_argument_noperiod(str);
	else
		ft_s_argument_period(str);
}

void	ft_xX_argument(void)
{
	unsigned int	nbr_hexa;
	int				nbr_char;

	nbr_hexa = va_arg(g_ap, unsigned int);
	nbr_char = ft_nbr_char(nbr_hexa);
	if (!g_dot)
		ft_xX_argument_noperiod();
	else
		ft_xX_argument_period();
}

void    ft_xX_argument_noperiod()
{
    if (g_flag == 1)
    {
        
    }
}

void	ft_d_argument(void)
{
	int	nbr;
	int	char_nbr;

	nbr = va_arg(g_ap, int);
	char_nbr = ft_calcul_nbr(nbr, 0, 10);
	if (!g_dot)
		ft_no_dot(nbr, char_nbr);
	// else
	// 	ft_period(nbr, char_nbr);
}

// void	ft_period(int nbr, int char_nbr)
// {
	
// }
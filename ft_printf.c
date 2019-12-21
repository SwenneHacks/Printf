/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 17:27:32 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/21 21:18:45 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void 	ft_printf(const char *str, ...)
{
	unsigned int 	index;
	t_info			info;
	va_list 		arg;

    index = 0;
    va_start(arg, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index += ft_percentage(str + index, &info);
		}
		else
		{
			write(1, &str[index], 1);
			index++;
		}
	}
	return ;
}

int		ft_percentage(const char *str, t_info *info)
{
	int		index;
	void	*cconv;

	//index = ft_flags(str, info);
	cconv = &ft_conversions(str[index]);
	if (cconv != NULL)
	{
		cconv(info);
	}
	else
		ft_unknown(info, str[i]);
	if (str[i] == '\0')
		return (i);
	return (i + 1);
}

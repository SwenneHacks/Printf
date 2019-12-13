/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:08:58 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/02 14:52:06 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}

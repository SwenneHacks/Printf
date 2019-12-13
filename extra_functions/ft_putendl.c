/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 14:33:29 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/30 22:32:24 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *s)
{
	if (s == NULL)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}

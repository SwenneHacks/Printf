/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:20:11 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/09 17:12:18 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FT_LSTSIZE: Counts the number of elements int a list
** 	and returns the length of the list.
*/

int		ft_lstsize(t_list *lst)
{
	int		index;

	index = 0;
	while (lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

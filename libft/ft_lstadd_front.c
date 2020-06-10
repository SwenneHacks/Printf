/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:20:34 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/09 17:24:20 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FT_LSTADD_FRONT: Adds the element new at the beginning of the list.
*/

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!(alst) || (!(new)))
		return ;
	new->next = *alst;
	*alst = new;
}

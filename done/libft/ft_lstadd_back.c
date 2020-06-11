/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 17:21:27 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/09 17:22:23 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FT_LSTADD_BACK: Adds the element new at the end of the list.
*/

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*head;

	if (!(alst))
		return ;
	head = *alst;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		ft_lstadd_front(alst, new);
}

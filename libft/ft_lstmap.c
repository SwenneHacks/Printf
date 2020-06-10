/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:14:12 by swofferh       #+#    #+#                */
/*   Updated: 2019/12/16 14:32:11 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FT_LSTMAP: Iterates the list lst and applies the function f to
** 	the content of each element. Creates a new list resulting of
** 	the successive applications of the function f. The del function
** 	is here to delete the content of an element if needed. Returns the
** 	new list or NULL if allocation fails.
*/

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*head;
	void		*content;

	if (!lst)
		return (0);
	head = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new = ft_lstnew((*f)(lst->content));
		if (!new)
			ft_lstclear(&lst, del);
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

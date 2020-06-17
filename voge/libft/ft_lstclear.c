/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:23:57 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/17 14:02:20 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FT_LSTCLEAR: Deletes and frees the given element and every
** 	successor of that element, using the function del and free.
** 	Finally, the pointer to the list must be set to NULL.
*/

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*link;
	t_list		*next_link;

	if (!(lst))
		return ;
	link = *lst;
	while (link)
	{
		next_link = link->next;
		del(link->content);
		free(link);
		link = next_link;
	}
	*lst = NULL;
}

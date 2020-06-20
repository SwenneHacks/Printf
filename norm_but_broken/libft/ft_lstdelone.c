/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 17:22:59 by swofferh      #+#    #+#                 */
/*   Updated: 2020/06/17 14:02:24 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FT_LSTDELONE: Takes as a parameter an element and frees the memory
** 	of the element’s content using the function del given as a parameter.
** 	The memory of next must not be freed under any circumstance.
*/

void		ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!(lst))
		return ;
	if (lst)
		del(lst->content);
	free(lst);
	lst = NULL;
}

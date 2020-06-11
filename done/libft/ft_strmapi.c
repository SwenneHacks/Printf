/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:57:17 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/25 17:41:05 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		index;

	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		result[index] = (*f)(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}

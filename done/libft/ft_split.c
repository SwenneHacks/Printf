/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:53:06 by swofferh       #+#    #+#                */
/*   Updated: 2019/11/26 22:32:51 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*free_words(int j, char **words)
{
	while (j != 0)
	{
		j--;
		if (words[j])
			free(words[j]);
	}
	free(words);
	return (NULL);
}

static int		word_count(char const *str, char c)
{
	int i;
	int loop;
	int count;

	i = 0;
	loop = 0;
	count = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			loop = 0;
		else if (loop == 0)
		{
			loop = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static int		word_len(char const *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char		**copy_words(char const *s, char c, char **words)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < word_count(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		words[j] = (char*)malloc(sizeof(char) * word_len(s, i, c) + 1);
		if (!(words[j]))
			return (free_words(j, words));
		while (s[i] != c && s[i] != '\0')
		{
			words[j][k] = s[i];
			k++;
			i++;
		}
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}

char			**ft_split(char const *s, char c)
{
	char **words;

	if (!(s))
		return (NULL);
	words = (char**)malloc(sizeof(char*) * (word_count(s, c) + 1));
	if (!(words))
		return (NULL);
	copy_words(s, c, words);
	return (words);
}

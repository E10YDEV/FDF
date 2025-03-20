/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:04:43 by eloymart          #+#    #+#             */
/*   Updated: 2024/11/17 19:44:48 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrings(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static int	*ft_wordlen(char const *s, char c, size_t count)
{
	int		*wordlen;
	size_t	i;

	wordlen = malloc(sizeof(int) * count);
	i = 0;
	if (!wordlen)
		return (NULL);
	while (i < count)
	{
		wordlen[i] = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			wordlen[i]++;
			s++;
		}
		i++;
	}
	return (wordlen);
}

static void	*ft_free(char **array, int *wordlen, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
	free(wordlen);
	return (NULL);
}

static char	*ft_copy(char const *s, char c, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		*wordlen;
	char	**array;

	count = ft_substrings(s, c);
	count = ft_substrings(s, c);
	i = 0;
	wordlen = ft_wordlen(s, c, count);
	array = malloc(sizeof(char *) * (count + 1));
	if (!s || !wordlen || !array)
		return (ft_free(array, wordlen, 0));
	while (i < count)
	{
		while (*s == c)
			s++;
		array[i] = ft_copy(s, c, wordlen[i]);
		if (!array[i])
			return (ft_free(array, wordlen, i));
		s += wordlen[i++];
	}
	array[count] = NULL;
	free(wordlen);
	return (array);
}

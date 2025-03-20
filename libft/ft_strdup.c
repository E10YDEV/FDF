/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:05:01 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/01 19:05:04 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*arr;

	i = ft_strlen(s);
	j = 0;
	arr = malloc(i + 1);
	if (arr == NULL)
		return (NULL);
	while (j < i)
	{
		arr[j] = s[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

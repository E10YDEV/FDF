/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:06:58 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/01 19:07:01 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *)&s[j]);
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:03:30 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/01 19:26:53 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newdestino;
	unsigned char	*newsrce;

	i = 0;
	newdestino = (unsigned char *)dest;
	newsrce = (unsigned char *)src;
	while (i < n)
	{
		newdestino[i] = newsrce[i];
		i++;
	}
	return (dest);
}

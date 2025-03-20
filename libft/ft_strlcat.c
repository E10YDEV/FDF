/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:05:27 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/01 19:05:30 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = dst_len;
	j = 0;
	while (src[j] != '\0' && (i < size - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}

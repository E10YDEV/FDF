/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:39:46 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/26 13:36:17 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new_str);
}

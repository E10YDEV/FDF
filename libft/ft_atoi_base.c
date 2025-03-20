/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:24:15 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/08 21:04:38 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int base)
{
	int		result;

	result = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * base + (*str - '0');
		else if (*str >= 'A' && *str <= 'F')
			result = result * base + (*str - 'A' + 10);
		else if (*str >= 'a' && *str <= 'f')
			result = result * base + (*str - 'a' + 10);
		else
			break ;
		str++;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:01:42 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/01 20:32:35 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_order(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_zero(void)
{
	char	*zero;

	zero = (char *)malloc(2);
	if (zero == NULL)
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

char	*ft_itoa(int n)
{
	size_t			i;
	unsigned int	nbr;
	char			*numero;

	if (n == 0)
		return (ft_zero());
	i = ft_order(n);
	nbr = n;
	numero = (char *)malloc(i + 1);
	if (numero == 0)
		return (NULL);
	if (n < 0)
	{
		numero[0] = '-';
		nbr = -n;
	}
	numero[i] = '\0';
	while (nbr > 0)
	{
		numero[--i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (numero);
}

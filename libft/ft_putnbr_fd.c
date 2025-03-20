/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:04:28 by eloymart          #+#    #+#             */
/*   Updated: 2024/10/01 19:04:30 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	char			digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	nbr = (unsigned int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)(-n);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	digit = (nbr % 10) + '0';
	write(fd, &digit, 1);
	return ;
}

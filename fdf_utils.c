/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:48:40 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/06 18:49:36 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_min_z(t_punto **map, int rows, int cols)
{
	int	min_z;
	int	y;
	int	x;

	min_z = map[0][0].z;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x].z < min_z)
				min_z = map[y][x].z;
			x++;
		}
		y++;
	}
	return (min_z);
}

int	get_max_z(t_punto **map, int rows, int cols)
{
	int	max_z;
	int	y;
	int	x;

	max_z = map[0][0].z;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x].z > max_z)
				max_z = map[y][x].z;
			x++;
		}
		y++;
	}
	return (max_z);
}

void	clear_image(mlx_image_t *image, int color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

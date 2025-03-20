/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:30:09 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/06 18:22:56 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_pixel_if_in_bounds(t_punto *point, mlx_image_t *image)
{
	if (point->iso_x >= 0 && (uint32_t)point->iso_x < image->width
		&& point->iso_y >= 0 && (uint32_t)point->iso_y < image->height)
	{
		mlx_put_pixel(image, point->iso_x, point->iso_y,
			point->color);
	}
}

void	calculate_next_step(t_bresenham *bres, int *coord, int delta, int step)
{
	bres->err += delta;
	*coord += step;
}

void	calculate_step_direction(int start_coord, int end_coord, int *step)
{
	if (start_coord < end_coord)
		*step = 1;
	else
		*step = -1;
}

void	initialize_bresenham(t_bresenham *bres)
{
	bres->dx = abs(bres->end.iso_x - bres->start.iso_x);
	bres->dy = abs(bres->end.iso_y - bres->start.iso_y);
	calculate_step_direction(bres->start.iso_x, bres->end.iso_x, &bres->sx);
	calculate_step_direction(bres->start.iso_y, bres->end.iso_y, &bres->sy);
	bres->err = bres->dx - bres->dy;
}

void	bresenham_line(t_punto start, t_punto end, mlx_image_t *image)
{
	t_bresenham	bres;

	bres.start = start;
	bres.end = end;
	initialize_bresenham(&bres);
	while (1)
	{
		plot_pixel_if_in_bounds(&bres.start, image);
		if (bres.start.iso_x == bres.end.iso_x
			&& bres.start.iso_y == bres.end.iso_y)
			break ;
		bres.e2 = bres.err * 2;
		if (bres.e2 > -bres.dy)
			calculate_next_step(&bres, &bres.start.iso_x, -bres.dy, bres.sx);
		if (bres.e2 < bres.dx)
			calculate_next_step(&bres, &bres.start.iso_y, bres.dx, bres.sy);
	}
}

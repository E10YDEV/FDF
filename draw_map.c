/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:04:36 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/12 12:57:59 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_point(float *x, float *y, t_global *global)
{
	float	x_new;
	float	y_new;
	float	center_x;
	float	center_y;

	center_x = COLS / 2.0;
	center_y = ROWS / 2.0;
	*x -= center_x;
	*y -= center_y;
	x_new = *x * cos(ANGLE) - *y * sin(ANGLE);
	y_new = *x * sin(ANGLE) + *y * cos(ANGLE);
	*x = x_new + center_x;
	*y = y_new + center_y;
}

void	iso_conversor(t_punto *point, t_global *global)
{
	float	x;
	float	y;

	x = point->x;
	y = point->y;
	rotate_point(&x, &y, global);
	point->iso_x = (x - y) * SCALE + OFF_X;
	point->iso_y = (x + y) * SCALE - point->z * FAC_Z + OFF_Y;
}

void	draw_cell(t_global *global, int x, int y)
{
	if (x < COLS - 1)
	{
		iso_conversor(&MAP[y][x], global);
		iso_conversor(&MAP[y][x + 1], global);
		bresenham_line(MAP[y][x], MAP[y][x + 1], IMG);
	}
	if (y < ROWS - 1)
	{
		iso_conversor(&MAP[y][x], global);
		iso_conversor(&MAP[y + 1][x], global);
		bresenham_line(MAP[y][x], MAP[y + 1][x], IMG);
	}
}

void	draw_map_rec(t_global *global, int x, int y)
{
	if (y >= ROWS)
		return ;
	if (x >= COLS)
	{
		draw_map_rec(global, 0, y + 1);
		return ;
	}
	draw_cell(global, x, y);
	draw_map_rec(global, x + 1, y);
}

void	draw_map(t_global *global)
{
	draw_map_rec(global, 0, 0);
}

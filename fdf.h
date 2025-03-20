/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:25:08 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/08 21:09:08 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "GNL/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "macros.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_punto
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			iso_x;
	int			iso_y;
}				t_punto;

typedef struct s_bresenham
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	t_punto		start;
	t_punto		end;
}				t_bresenham;

typedef struct s_global
{
	int			window_width;
	int			window_height;
	float		escala_x;
	float		offset_x;
	float		offset_y;
	float		rotation_angle;
	float		z_factor;
	t_punto		**map;
	int			rows;
	int			cols;
	int			min_z;
	int			max_z;
	mlx_image_t	*image;
	mlx_t		*mlx;
}				t_global;

t_punto			**parse_map(char *file, int rows, int cols);
void			get_map_size(char *file, int *rows, int *cols);
void			bresenham_line(t_punto start, t_punto end, mlx_image_t *image);
void			draw_map(t_global *global);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			clear_image(mlx_image_t *image, int color);
int				get_max_z(t_punto **map, int rows, int cols);
int				get_min_z(t_punto **map, int rows, int cols);
void			clear_image(mlx_image_t *image, int color);
void			my_scrollhook(double xdelta, double ydelta, void *param);
t_punto			*allocate_row(int cols);
int				normalize_rgb_to_rgba(int color);
void			get_map_size(char *file, int *rows, int *cols);
int				count_columns(char *line);
void			free_fdf(t_global *global);

#endif
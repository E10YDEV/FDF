/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:05:06 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/12 13:46:49 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_global(t_global *global, char **argv)
{
	get_map_size(argv[1], &ROWS, &COLS);
	MAP = parse_map(argv[1], ROWS, COLS);
	WIDTH = 2000;
	HEIGHT = 1600;
	ANGLE = 0.0;
	MAXI_Z = get_max_z(MAP, ROWS, COLS);
	MINI_Z = get_min_z(MAP, ROWS, COLS);
	FAC_Z = fmax(1, 200.0 / COLS);
	SCALE = fmin((float)WIDTH / (COLS * 2), (float)HEIGHT / ((ROWS + COLS - 2)
				+ abs(MAXI_Z - MINI_Z)));
	OFF_X = (WIDTH - (COLS - ROWS) * SCALE) / 2.0;
	OFF_Y = (HEIGHT - (ROWS + COLS) * SCALE) / 2.0;
	MLX = mlx_init(WIDTH, HEIGHT, "FDF", false);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
}

void	free_map(t_punto **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_fdf(t_global *global)
{
	mlx_terminate(MLX);
	free_map(MAP, ROWS);
	free(global);
}

int	main(int argc, char **argv)
{
	t_global	*global;

	if (argc != 2)
	{
		perror("Usage: ./fdf <map_file>\n");
		return (1);
	}
	global = malloc(sizeof(t_global));
	if (!global)
	{
		free_fdf(global);
		return (1);
	}
	init_global(global, argv);
	draw_map(global);
	if (mlx_image_to_window(MLX, IMG, 0, 0) == -1)
	{
		free_fdf(global);
		return (0);
	}
	mlx_key_hook(MLX, &my_keyhook, global);
	mlx_scroll_hook(MLX, &my_scrollhook, global);
	mlx_loop(MLX);
	free_fdf(global);
	return (0);
}

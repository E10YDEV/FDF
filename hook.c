/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloymart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:25:08 by eloymart          #+#    #+#             */
/*   Updated: 2025/01/08 21:09:08 by eloymart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_draw_launch(t_global *global)
{
	clear_image(IMG, 0x00000000);
	draw_map(global);
	mlx_image_to_window(MLX, IMG, 0, 0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(MLX);
	else if (keydata.key == MLX_KEY_A)
		OFF_X -= 10.0;
	else if (keydata.key == MLX_KEY_D)
		OFF_X += 10.0;
	else if (keydata.key == MLX_KEY_W)
		OFF_Y -= 10.0;
	else if (keydata.key == MLX_KEY_S)
		OFF_Y += 10.0;
	else if (keydata.key == MLX_KEY_LEFT)
		ANGLE -= 0.1;
	else if (keydata.key == MLX_KEY_RIGHT)
		ANGLE += 0.1;
	else if (keydata.key == MLX_KEY_UP)
		FAC_Z += 0.1;
	else if (keydata.key == MLX_KEY_DOWN)
		FAC_Z -= 0.1;
	else
		return ;
	clear_draw_launch(global);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_global	*global;

	global = (t_global *)param;
	(void)xdelta;
	if (ydelta < 0)
	{
		SCALE += 0.5;
	}
	else if (ydelta > 0)
	{
		SCALE -= 0.5;
		if (SCALE < 0)
			SCALE = 0;
	}
	clear_draw_launch(global);
}

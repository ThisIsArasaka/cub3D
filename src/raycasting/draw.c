/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:02:02 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/13 13:11:12 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	draw_floor(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(&data->mlx->img, x, y, create_trgb(0,
					data->textures.floor->red, data->textures.floor->green,
					data->textures.floor->blue));
			y++;
		}
		x++;
	}
}

void	draw_ceiling(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			my_mlx_pixel_put(&data->mlx->img, x, y, create_trgb(0,
					data->textures.ceiling->red, data->textures.ceiling->green,
					data->textures.ceiling->blue));
			y++;
		}
		x++;
	}
}

void	draw_walls(t_game *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		data->ray.map_x = (int)data->player->x;
		data->ray.map_y = (int)data->player->y;
		data->ray.ray_angle = data->player->dir - FOV / 2 + (x * FOV / WIDTH);
		data->ray.ray_dirx = cos(data->ray.ray_angle);
		data->ray.ray_diry = sin(data->ray.ray_angle);
		if (data->ray.ray_dirx == 0)
			data->ray.delta_distx = 1e30;
		else
			data->ray.delta_distx = fabs(1 / data->ray.ray_dirx);
		if (data->ray.ray_diry == 0)
			data->ray.delta_disty = 1e30;
		else
			data->ray.delta_disty = fabs(1 / data->ray.ray_diry);
		init_dda(data);
		dda(data, x);
		x++;
	}
}

t_img	*set_dino(t_game *data)
{
	clock_t	time;

	time = clock();
	if (time - data->textures.dino.time > 100000)
	{
		data->textures.dino.time = time;
		data->textures.dino.frame = (data->textures.dino.frame + 1) % 2;
	}
	if (data->textures.dino.state == 0)
		return (&data->textures.dino.idle[data->textures.dino.frame]);
	else
		return (&data->textures.dino.runnin[data->textures.dino.frame]);
}

void	draw_dino(t_game *data)
{
	int		x;
	int		y;
	int		color;
	t_img	*dino;

	dino = set_dino(data);
	x = WIDTH - dino->width;
	while (x < WIDTH)
	{
		y = 0;
		while (y < dino->height)
		{
			color = get_pixel_color(dino, (x - (WIDTH - dino->width)), y);
			if (color > 0)
				my_mlx_pixel_put(&data->mlx->img, x, y, color);
			y++;
		}
		x++;
	}
}

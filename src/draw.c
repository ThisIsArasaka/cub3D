/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:02:02 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/23 19:50:02 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#define WALL 0x00FF88FF

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1920)
	{
		y = 1080 / 2;
		while (y < 1080)
		{
			my_mlx_pixel_put(&data->img, x, y, data->map.floor_color);
			y++;
		}
		x++;
	}
}

void	draw_ceiling(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080 / 2)
		{
			my_mlx_pixel_put(&data->img, x, y, data->map.ceiling_color);
			y++;
		}
		x++;
	}
}

void	dda(t_data *data, int x)
{
	int		hit;
	double	wall_dist;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	double	player_x;
	double	player_y;
	int		map[9][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0,
				0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0,
				1, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 0, 0,
				1, 0, 1}, {1, 0, 1, 1, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0,
				0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	hit = 0;
	player_x = data->player.x;
	player_y = data->player.y;
	if (data->ray.ray_dirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.distx = (data->player.x - (int)data->player.x)
			* data->ray.ray_dirx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.distx = ((int)data->player.x + 1 - data->player.x)
			* data->ray.ray_dirx;
	}
	if (data->ray.ray_diry < 0)
	{
		data->ray.stepy = -1;
		data->ray.disty = (data->player.y - (int)data->player.y)
			* data->ray.ray_diry;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.disty = ((int)data->player.y + 1 - data->player.y)
			* data->ray.ray_diry;
	}
	while (!hit)
	{
		if (data->ray.distx < data->ray.disty)
		{
			data->ray.distx += data->ray.ray_dirx;
			player_x += data->ray.stepx;
		}
		else
		{
			data->ray.disty += data->ray.ray_diry;
			player_y += data->ray.stepy;
		}
		if (map[(int)player_y][(int)player_x] == 1)
			hit = 1;
	}
	wall_dist = sqrt(pow(player_x - data->player.x, 2) + pow(player_y
				- data->player.y, 2));
	wall_height = 1080 / wall_dist;
	wall_start = 1080 / 2 - wall_height / 2;
	wall_end = 1080 / 2 + wall_height / 2;
	while (wall_start < wall_end)
	{
		my_mlx_pixel_put(&data->img, x, wall_start, WALL);
		wall_start++;
	}
}

void	draw_walls(t_data *data)
{
	int		x;
	double	FOV;

	FOV = PI / 3;
	x = 0;
	while (x < 1920)
	{
		data->ray.ray_angle = data->player.dir - FOV / 2 + (x * FOV / 1920);
		data->ray.ray_dirx = cos(data->ray.ray_angle);
		data->ray.ray_diry = sin(data->ray.ray_angle);
		dda(data, x);
		x++;
	}
}

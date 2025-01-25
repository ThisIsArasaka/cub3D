/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:02:02 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/25 15:26:14 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#define WALL_NORTH 0x00FF88FF
#define WALL_SOUTH 0x00FFFFAA
#define WALL_EAST 0x00CCFFFF
#define WALL_WEST 0x00FFFF40

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

void	put_wall_pixel(t_data *data, int x)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;

	wall_height = 1080 / data->ray.wall_dist;
	wall_start = 1080 / 2 - wall_height / 2;
	wall_end = 1080 / 2 + wall_height / 2;
	while (wall_start < wall_end)
	{
		if (data->ray.ray_dirx > 0 && data->ray.ray_diry > 0)
			my_mlx_pixel_put(&data->img, x, wall_start, WALL_NORTH);
		else if (data->ray.ray_dirx > 0 && data->ray.ray_diry < 0)
			my_mlx_pixel_put(&data->img, x, wall_start, WALL_SOUTH);
		else if (data->ray.ray_dirx < 0 && data->ray.ray_diry > 0)
			my_mlx_pixel_put(&data->img, x, wall_start, WALL_EAST);
		else if (data->ray.ray_dirx < 0 && data->ray.ray_diry < 0)
			my_mlx_pixel_put(&data->img, x, wall_start, WALL_WEST);
		wall_start++;
	}
}

void	dda(t_data *data, int x)
{
	int		hit;
	int		side;
	double	player_x;
	double	player_y;
	int		map[9][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0,
				0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0,
				1, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 0, 0,
				1, 0, 1}, {1, 0, 1, 1, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0,
				0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	// double	wall_dist;
	// int		wall_height;
	// int		wall_start;
	// int		wall_end;
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
			side = 0;
		}
		else
		{
			data->ray.disty += data->ray.ray_diry;
			player_y += data->ray.stepy;
			side = 1;
		}
		if (map[(int)player_y][(int)player_x] == 1)
			hit = 1;
	}
	if (side == 0)
	{
		data->ray.wall_dist = (player_x - data->player.x + (1 - data->ray.stepx)
				/ 2) / data->ray.ray_dirx;
	}
	else
	{
		data->ray.wall_dist = (player_y - data->player.y + (1 - data->ray.stepy)
				/ 2) / data->ray.ray_diry;
	}
	put_wall_pixel(data, x);
	// wall_dist = sqrt(pow(player_x - data->player.x, 2) + pow(player_y
	// 			- data->player.y, 2));
	// wall_height = 1080 / wall_dist;
	// wall_start = 1080 / 2 - wall_height / 2;
	// wall_end = 1080 / 2 + wall_height / 2;
	// while (wall_start < wall_end)
	// {
	// 	my_mlx_pixel_put(&data->img, x, wall_start, WALL);
	// 	wall_start++;
	// }
}

void	draw_walls(t_data *data)
{
	int	x;

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

void	draw_map(t_data *data)
{
	int	map[9][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0,
			0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0,
			1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
			{1, 0, 1, 1, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
			1, 1, 1, 1, 1, 1, 1, 1, 1}};
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;

	y = 0;
	screen_y = 0;
	while (y < 9)
	{
		x = 0;
		screen_x = 0;
		while (x < 10)
		{
			while (screen_x < 19 * (x + 1))
			{
				screen_y = 19 * y;
				while (screen_y < 19 * (y + 1))
				{
					if (y == (int)data->player.y && x == (int)data->player.x)
						my_mlx_pixel_put(&data->img, screen_x, screen_y,
							0x00FF00FF);
					else if (map[y][x] == 1)
						my_mlx_pixel_put(&data->img, screen_x, screen_y,
							0x00FF0000);
					else if (map[y][x] == 0)
						my_mlx_pixel_put(&data->img, screen_x, screen_y,
							0x000000FF);
					screen_y++;
				}
				screen_x++;
			}
			x++;
		}
		y++;
	}
}

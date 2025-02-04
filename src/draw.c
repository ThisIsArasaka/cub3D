/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:02:02 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/04 14:05:55 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
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
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			my_mlx_pixel_put(&data->img, x, y, data->map.ceiling_color);
			y++;
		}
		x++;
	}
}

void	put_wall_pixel(t_data *data, int x, int side, int door)
{
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		color;
	double	wall_x;
	int		texture_x;
	int		texture_y;
	double	step;
	double	tex_pos;
	t_img	*texture;

	wall_height = HEIGHT / data->ray.wall_dist;
	wall_start = HEIGHT / 2 - wall_height / 2;
	wall_end = HEIGHT / 2 + wall_height / 2;
	if (side == 0 && !door)
	{
		if (data->ray.ray_dirx > 0)
			texture = &data->texture.east;
		else
			texture = &data->texture.west;
	}
	else if (side == 1 && !door)
	{
		if (data->ray.ray_diry > 0)
			texture = &data->texture.south;
		else
			texture = &data->texture.north;
	}
	else
		texture = &data->texture.door;
	if (side == 0)
		wall_x = data->player.y + data->ray.wall_dist * data->ray.ray_diry;
	else
		wall_x = data->player.x + data->ray.wall_dist * data->ray.ray_dirx;
	wall_x -= floor(wall_x);
	texture_x = wall_x * texture->width;
	if (side == 0 && data->ray.ray_dirx > 0)
		texture_x = texture->width - texture_x - 1;
	if (side == 1 && data->ray.ray_diry < 0)
		texture_x = texture->width - texture_x - 1;
	step = 1.0 * texture->height / wall_height;
	tex_pos = (wall_start - HEIGHT / 2 + wall_height / 2) * step;
	while (wall_start < wall_end)
	{
		texture_y = (int)tex_pos % (texture->height - 1);
		tex_pos += step;
		color = get_pixel_color(texture, texture_x, texture_y);
		my_mlx_pixel_put(&data->img, x, wall_start, color);
		wall_start++;
	}
}

void	dda(t_data *data, int x)
{
	int	hit;
	int	side;
	int	door;
	char map[15][15] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '1', '1', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', 'P', '1', '1', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};

	hit = 0;
	door = 0;
	while (!hit)
	{
		if (data->ray.distx < data->ray.disty)
		{
			data->ray.distx += data->ray.delta_distx;
			data->ray.map_x += data->ray.stepx;
			side = 0;
		}
		else
		{
			data->ray.disty += data->ray.delta_disty;
			data->ray.map_y += data->ray.stepy;
			side = 1;
		}
		if (map[data->ray.map_y][data->ray.map_x] == '1')
			hit = 1;
		else if (map[data->ray.map_y][data->ray.map_x] == 'P')
		{
			door = 1;
			hit = 1;
		}
	}
	if (side == 0)
	{
		data->ray.wall_dist = (data->ray.map_x - data->player.x + (1
					- data->ray.stepx) / 2) / data->ray.ray_dirx;
	}
	else
	{
		data->ray.wall_dist = (data->ray.map_y - data->player.y + (1
					- data->ray.stepy) / 2) / data->ray.ray_diry;
	}
	data->ray.wall_dist *= cos(data->ray.ray_angle - data->player.dir);
	if (data->ray.wall_dist < 0)
		data->ray.wall_dist = 1e30;
	put_wall_pixel(data, x, side, door);
}

void	init_dda(t_data *data)
{
	if (data->ray.ray_dirx == 0)
		data->ray.delta_distx = 1e30;
	else
		data->ray.delta_distx = fabs(1 / data->ray.ray_dirx);
	if (data->ray.ray_diry == 0)
		data->ray.delta_disty = 1e30;
	else
		data->ray.delta_disty = fabs(1 / data->ray.ray_diry);
	if (data->ray.ray_dirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.distx = (data->player.x - (int)data->player.x)
			* data->ray.delta_distx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.distx = ((int)data->player.x + 1 - data->player.x)
			* data->ray.delta_distx;
	}
	if (data->ray.ray_diry < 0)
	{
		data->ray.stepy = -1;
		data->ray.disty = (data->player.y - (int)data->player.y)
			* data->ray.delta_disty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.disty = ((int)data->player.y + 1 - data->player.y)
			* data->ray.delta_disty;
	}
}

void	draw_walls(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		data->ray.map_x = (int)data->player.x;
		data->ray.map_y = (int)data->player.y;
		data->ray.ray_angle = data->player.dir - FOV / 2 + (x * FOV / WIDTH);
		data->ray.ray_dirx = cos(data->ray.ray_angle);
		data->ray.ray_diry = sin(data->ray.ray_angle);
		init_dda(data);
		dda(data, x);
		x++;
	}
}

void	draw_player_map(t_data *data)
{
	int		player_x;
	int		player_y;
	int		arrow_x;
	int		arrow_y;
	double	angle;
	int		i;

	player_x = 75 + cos(data->player.dir) * 5;
	player_y = 75 + sin(data->player.dir) * 5;
	i = 1;
	while (i < 10)
	{
		angle = data->player.dir + (PI * 5) / 6;
		arrow_x = player_x + cos(angle) * i;
		arrow_y = player_y + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, 0x00FF0000);
		angle = data->player.dir - (PI * 5) / 6;
		arrow_x = player_x + cos(angle) * i;
		arrow_y = player_y + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, 0x00FF0000);
		i++;
	}
	player_x = arrow_x;
	player_y = arrow_y;
	i = 1;
	while (i < 10)
	{
		angle = data->player.dir + PI / 2;
		arrow_x = player_x + cos(angle) * i;
		arrow_y = player_y + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, 0x00FF0000);
		i++;
	}
}

void	draw_map(t_data *data)
{
	char map[15][15] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '1', '1', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', 'P', '1', '1', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	int		screen_x;
	int		screen_y;
	double	map_x;
	double	map_y;

	screen_y = 0;
	while (screen_y < 150)
	{
		screen_x = 0;
		while (screen_x < 150)
		{
			map_x = data->player.x - 5 + ((double)screen_x - 25) / MINIMAP_SIZE;
			map_y = data->player.y - 5 + ((double)screen_y - 25) / MINIMAP_SIZE;
			if (map_x >= 0 && map_x < data->map.width && map_y >= 0
				&& map_y < data->map.height)
			{
				if (map[(int)map_y][(int)map_x] == '1')
					my_mlx_pixel_put(&data->img, screen_x, screen_y,
						0x00FF0000);
				else
					my_mlx_pixel_put(&data->img, screen_x, screen_y,
						0x6600FF00);
			}
			screen_x++;
		}
		screen_y++;
	}
	draw_player_map(data);
}

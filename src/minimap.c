/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:17:27 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/12 11:03:12 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	draw_front_arrow(t_data *data)
{
	int		arrow_x;
	int		arrow_y;
	double	angle;
	int		i;

	i = 1;
	while (i < 15)
	{
		angle = data->player.dir + (PI * 5) / 6;
		arrow_x = (100 + cos(data->player.dir) * 8) + cos(angle) * i;
		arrow_y = (100 + sin(data->player.dir) * 8) + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, MINIMAP_COLOR_PLAYER);
		angle = data->player.dir - (PI * 5) / 6;
		arrow_x = (100 + cos(data->player.dir) * 8) + cos(angle) * i;
		arrow_y = (100 + sin(data->player.dir) * 8) + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, MINIMAP_COLOR_PLAYER);
		i++;
	}
}

void	draw_player_map(t_data *data)
{
	int		arrow_x;
	int		arrow_y;
	double	angle;
	int		i;

	draw_front_arrow(data);
	i = 1;
	while (i < 8)
	{
		angle = data->player.dir + (PI * 2) / 3;
		arrow_x = 100 + cos(angle) * i;
		arrow_y = 100 + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, MINIMAP_COLOR_PLAYER);
		angle = data->player.dir - (PI * 2) / 3;
		arrow_x = 100 + cos(angle) * i;
		arrow_y = 100 + sin(angle) * i;
		my_mlx_pixel_put(&data->img, arrow_x, arrow_y, MINIMAP_COLOR_PLAYER);
		i++;
	}
}

void	set_pixel_map(t_data *data, int screen_x, int screen_y)
{
	double	map_x;
	double	map_y;

	map_x = data->player.x - 5 + ((double)screen_x - 25) / MINIMAP_SIZE;
	map_y = data->player.y - 5 + ((double)screen_y - 25) / MINIMAP_SIZE;
	if (map_x >= 0 && map_x < data->map.width && map_y >= 0
		&& map_y < data->map.height)
	{
		if (data->map.map[(int)map_y][(int)map_x] == '1')
			my_mlx_pixel_put(&data->img, screen_x, screen_y,
				MINIMAP_COLOR_WALL);
		else if (data->map.map[(int)map_y][(int)map_x] == 'P'
			|| data->map.map[(int)map_y][(int)map_x] == 'O')
			my_mlx_pixel_put(&data->img, screen_x, screen_y,
				MINIMAP_COLOR_DOOR);
		else if (data->map.map[(int)map_y][(int)map_x] == '0')
			my_mlx_pixel_put(&data->img, screen_x, screen_y,
				MINIMAP_COLOR_FLOOR);
	}
}

void	draw_map(t_data *data)
{
	int	screen_x;
	int	screen_y;

	screen_y = 0;
	while (screen_y < 200)
	{
		screen_x = 0;
		while (screen_x < 200)
		{
			set_pixel_map(data, screen_x, screen_y);
			screen_x++;
		}
		screen_y++;
	}
	draw_player_map(data);
}

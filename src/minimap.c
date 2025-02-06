/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:17:27 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/06 14:25:31 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

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
				if (data->map.map[(int)map_y][(int)map_x] == '1')
					my_mlx_pixel_put(&data->img, screen_x, screen_y,
						0x00FF0000);
				else if (data->map.map[(int)map_y][(int)map_x] == 'P')
					my_mlx_pixel_put(&data->img, screen_x, screen_y,
						0x000087FF);
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
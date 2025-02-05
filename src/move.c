/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:42:21 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/05 10:50:35 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	is_valid_position(t_data *data, double *new_x, double *new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)*new_x;
	map_y = (int)*new_y;
	if (data->map.map[(int)data->player.y][map_x] != '0'
		&& data->map.map[(int)data->player.y][map_x] != 'O')
		*new_x = data->player.x;
	if (data->map.map[map_y][(int)data->player.x] != '0'
		&& data->map.map[map_y][(int)data->player.x] != 'O')
		*new_y = data->player.y;
}

void	move_forward(t_data *data, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == XK_w)
	{
		new_x = data->player.x + cos(data->player.dir) * SPEED;
		new_y = data->player.y + sin(data->player.dir) * SPEED;
		is_valid_position(data, &new_x, &new_y);
		data->player.x = new_x;
		data->player.y = new_y;
	}
	if (keycode == XK_s)
	{
		new_x = data->player.x - cos(data->player.dir) * SPEED;
		new_y = data->player.y - sin(data->player.dir) * SPEED;
		is_valid_position(data, &new_x, &new_y);
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	move_sideways(t_data *data, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == XK_a)
	{
		new_x = data->player.x + sin(data->player.dir) * SPEED;
		new_y = data->player.y - cos(data->player.dir) * SPEED;
		is_valid_position(data, &new_x, &new_y);
		data->player.x = new_x;
		data->player.y = new_y;
	}
	if (keycode == XK_d)
	{
		new_x = data->player.x - sin(data->player.dir) * SPEED;
		new_y = data->player.y + cos(data->player.dir) * SPEED;
		is_valid_position(data, &new_x, &new_y);
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	open_door(t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(data->player.x + cos(data->player.dir));
	map_y = (int)(data->player.y + sin(data->player.dir));
	if (data->map.map[map_y][map_x] == '1')
		return ;
	if (data->map.map[map_y][map_x] == 'P')
		data->map.map[map_y][map_x] = 'O';
	else if (data->map.map[map_y][map_x] == 'O')
		data->map.map[map_y][map_x] = 'P';
}

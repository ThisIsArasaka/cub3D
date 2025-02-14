/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:42:21 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/14 10:55:36 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_valid_position(t_game *data, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (data->map->map[(int)data->player->y][map_x] != '0'
		&& data->map->map[(int)data->player->y][map_x] != 'O')
		return (0);
	if (data->map->map[map_y][(int)data->player->x] != '0'
		&& data->map->map[map_y][(int)data->player->x] != 'O')
		return (0);
	return (1);
}

void	init_check_forward(t_game *data, int key)
{
	if (key == XK_w)
	{
		data->player->new_x = data->player->x + cos(data->player->dir) * SPEED;
		data->player->new_y = data->player->y + sin(data->player->dir) * SPEED;
		data->player->check_x = data->player->x + cos(data->player->dir)
			* (SPEED + MARGIN);
		data->player->check_y = data->player->y + sin(data->player->dir)
			* (SPEED + MARGIN);
	}
	if (key == XK_s)
	{
		data->player->new_x = data->player->x - cos(data->player->dir) * SPEED;
		data->player->new_y = data->player->y - sin(data->player->dir) * SPEED;
		data->player->check_x = data->player->x - cos(data->player->dir)
			* (SPEED + MARGIN);
		data->player->check_y = data->player->y - sin(data->player->dir)
			* (SPEED + MARGIN);
	}
}

void	init_check_sideways(t_game *data, int key)
{
	if (key == XK_a)
	{
		data->player->new_x = data->player->x + sin(data->player->dir) * SPEED;
		data->player->new_y = data->player->y - cos(data->player->dir) * SPEED;
		data->player->check_x = data->player->x + sin(data->player->dir)
			* (SPEED + MARGIN);
		data->player->check_y = data->player->y - cos(data->player->dir)
			* (SPEED + MARGIN);
	}
	if (key == XK_d)
	{
		data->player->new_x = data->player->x - sin(data->player->dir) * SPEED;
		data->player->new_y = data->player->y + cos(data->player->dir) * SPEED;
		data->player->check_x = data->player->x - sin(data->player->dir)
			* (SPEED + MARGIN);
		data->player->check_y = data->player->y + cos(data->player->dir)
			* (SPEED + MARGIN);
	}
}

void	move_forward(t_game *data, int keycode)
{
	init_check_forward(data, keycode);
	if (keycode == XK_w)
	{
		if (is_valid_position(data, data->player->check_x, data->player->y))
			data->player->x = data->player->new_x;
		if (is_valid_position(data, data->player->x, data->player->check_y))
			data->player->y = data->player->new_y;
	}
	if (keycode == XK_s)
	{
		if (is_valid_position(data, data->player->check_x, data->player->y))
			data->player->x = data->player->new_x;
		if (is_valid_position(data, data->player->x, data->player->check_y))
			data->player->y = data->player->new_y;
	}
}

void	move_sideways(t_game *data, int keycode)
{
	init_check_sideways(data, keycode);
	if (keycode == XK_a)
	{
		if (is_valid_position(data, data->player->check_x, data->player->y))
			data->player->x = data->player->new_x;
		if (is_valid_position(data, data->player->x, data->player->check_y))
			data->player->y = data->player->new_y;
	}
	if (keycode == XK_d)
	{
		if (is_valid_position(data, data->player->check_x, data->player->y))
			data->player->x = data->player->new_x;
		if (is_valid_position(data, data->player->x, data->player->check_y))
			data->player->y = data->player->new_y;
	}
}

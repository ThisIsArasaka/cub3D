/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:42:21 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/26 20:33:36 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_valid_position(double new_x, double new_y)
{
	int	map_x;
	int	map_y;
	int	map[9][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0,
			0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0,
			1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
			{1, 0, 1, 1, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
			1, 1, 1, 1, 1, 1, 1, 1, 1}};

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map[map_y][map_x] == 0)
		return (1);
	return (0);
}

void	move_forward(t_data *data, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == XK_w)
	{
		new_x = data->player.x + cos(data->player.dir) * SPEED;
		new_y = data->player.y + sin(data->player.dir) * SPEED;
		if (is_valid_position(new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (keycode == XK_s)
	{
		new_x = data->player.x - cos(data->player.dir) * SPEED;
		new_y = data->player.y - sin(data->player.dir) * SPEED;
		if (is_valid_position(new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
}
void	move_sideways(t_data *data, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == XK_a)
	{
		new_x = data->player.x - cos(data->player.dir) * SPEED;
		new_y = data->player.y + sin(data->player.dir) * SPEED;
		if (is_valid_position(new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (keycode == XK_d)
	{
		new_x = data->player.x + cos(data->player.dir) * SPEED;
		new_y = data->player.y - sin(data->player.dir) * SPEED;
		if (is_valid_position(new_x, new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
}

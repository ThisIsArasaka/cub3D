/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:42:21 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/03 09:19:26 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	is_valid_position(t_data *data, double *new_x, double *new_y)
{
	int	map_x;
	int	map_y;
	int	map[15][15] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1}, 
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, 
		{1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, 
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1}, 
		{1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	// int	map[9][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0,
	//		0,
	// 		0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0,
	// 		1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	// 		{1, 0, 1, 1, 1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
	// 		1, 1, 1, 1, 1, 1, 1, 1, 1}};
	map_x = (int)*new_x;
	map_y = (int)*new_y;
	if (map[(int)data->player.y][map_x] == 1)
		*new_x = data->player.x;
	if (map[map_y][(int)data->player.x] == 1)
		*new_y = data->player.y;
	return (1);
}

void	move_forward(t_data *data, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == XK_w)
	{
		new_x = data->player.x + cos(data->player.dir) * SPEED;
		new_y = data->player.y + sin(data->player.dir) * SPEED;
		if (is_valid_position(data, &new_x, &new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (keycode == XK_s)
	{
		new_x = data->player.x - cos(data->player.dir) * SPEED;
		new_y = data->player.y - sin(data->player.dir) * SPEED;
		if (is_valid_position(data, &new_x, &new_y))
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
		new_x = data->player.x + sin(data->player.dir) * SPEED;
		new_y = data->player.y - cos(data->player.dir) * SPEED;
		if (is_valid_position(data, &new_x, &new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
	if (keycode == XK_d)
	{
		new_x = data->player.x - sin(data->player.dir) * SPEED;
		new_y = data->player.y + cos(data->player.dir) * SPEED;
		if (is_valid_position(data, &new_x, &new_y))
		{
			data->player.x = new_x;
			data->player.y = new_y;
		}
	}
}

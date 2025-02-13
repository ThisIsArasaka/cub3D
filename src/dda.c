/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:57:39 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/13 09:13:01 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_dda(t_data *data)
{
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

void	dda_loop(t_data *data, int *side, int *door)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (data->ray.distx < data->ray.disty)
		{
			data->ray.distx += data->ray.delta_distx;
			data->ray.map_x += data->ray.stepx;
			*side = 0;
		}
		else
		{
			data->ray.disty += data->ray.delta_disty;
			data->ray.map_y += data->ray.stepy;
			*side = 1;
		}
		if (data->map.map[data->ray.map_y][data->ray.map_x] == '1')
			hit = 1;
		else if (data->map.map[data->ray.map_y][data->ray.map_x] == 'P')
		{
			*door = 1;
			hit = 1;
		}
	}
}

void	dda(t_data *data, int x)
{
	int	side;
	int	door;

	door = 0;
	dda_loop(data, &side, &door);
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
	data->ray.wall_dist_corrected = data->ray.wall_dist
		* cos(data->ray.ray_angle - data->player.dir);
	if (data->ray.wall_dist < 0)
		data->ray.wall_dist = 1e30;
	put_wall_pixel(data, x, side, door);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:02:11 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/14 10:57:20 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

t_img	*set_texture(t_game *data, int side, int door)
{
	if (side == 0 && !door)
	{
		if (data->ray.ray_dirx > 0)
			return (&data->textures.east);
		else
			return (&data->textures.west);
	}
	else if (side == 1 && !door)
	{
		if (data->ray.ray_diry > 0)
			return (&data->textures.south);
		else
			return (&data->textures.north);
	}
	else
		return (&data->textures.door);
}

void	draw_wall_pixel(t_game *data, t_img *texture, int x)
{
	while (data->ray.wall_start < data->ray.wall_end)
	{
		data->ray.texture_y = (int)data->ray.tex_pos % (texture->height - 1);
		data->ray.tex_pos += data->ray.step;
		data->ray.color = get_pixel_color(texture, data->ray.texture_x,
				data->ray.texture_y);
		my_mlx_pixel_put(&data->mlx->img, x, data->ray.wall_start,
			data->ray.color);
		data->ray.wall_start++;
	}
}

void	put_wall_pixel(t_game *data, int x, int side, int door)
{
	t_img	*texture;

	texture = set_texture(data, side, door);
	data->ray.wall_height = HEIGHT / data->ray.wall_dist_corrected;
	data->ray.wall_start = HEIGHT / 2 - data->ray.wall_height / 2;
	data->ray.wall_end = HEIGHT / 2 + data->ray.wall_height / 2;
	if (side == 0)
		data->ray.wall_x = data->player->y + data->ray.wall_dist
			* data->ray.ray_diry;
	else
		data->ray.wall_x = data->player->x + data->ray.wall_dist
			* data->ray.ray_dirx;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.texture_x = data->ray.wall_x * texture->width;
	if (side == 0 && data->ray.ray_dirx > 0)
		data->ray.texture_x = texture->width - data->ray.texture_x - 1;
	if (side == 1 && data->ray.ray_diry < 0)
		data->ray.texture_x = texture->width - data->ray.texture_x - 1;
	data->ray.step = 1.0 * texture->height / data->ray.wall_height;
	data->ray.tex_pos = (data->ray.wall_start - HEIGHT / 2
			+ data->ray.wall_height / 2) * data->ray.step;
	draw_wall_pixel(data, texture, x);
}

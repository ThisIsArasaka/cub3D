/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:47:31 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/28 12:10:44 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_texture_img(t_data *data)
{
	data->texture.north.addr = mlx_get_data_addr(data->texture.north.img,
			&data->texture.north.bpp, &data->texture.north.line_len,
			&data->texture.north.endian);
	data->texture.south.addr = mlx_get_data_addr(data->texture.south.img,
			&data->texture.south.bpp, &data->texture.south.line_len,
			&data->texture.south.endian);
	data->texture.east.addr = mlx_get_data_addr(data->texture.east.img,
			&data->texture.east.bpp, &data->texture.east.line_len,
			&data->texture.east.endian);
	data->texture.west.addr = mlx_get_data_addr(data->texture.west.img,
			&data->texture.west.bpp, &data->texture.west.line_len,
			&data->texture.west.endian);
}

int	init_texture(t_data *data)
{
	data->texture.north.img = mlx_xpm_file_to_image(data->mlx,
			"sprite/NORTH_WALL.xpm", &data->texture.north.width,
			&data->texture.north.height);
	data->texture.south.img = mlx_xpm_file_to_image(data->mlx,
			"sprite/SOUTH_WALL.xpm", &data->texture.south.width,
			&data->texture.south.height);
	data->texture.east.img = mlx_xpm_file_to_image(data->mlx,
			"sprite/EAST_WALL.xpm", &data->texture.east.width,
			&data->texture.east.height);
	data->texture.west.img = mlx_xpm_file_to_image(data->mlx,
			"sprite/WEST_WALL.xpm", &data->texture.west.width,
			&data->texture.west.height);
	if (!data->texture.north.img || !data->texture.south.img
		|| !data->texture.east.img || !data->texture.west.img)
		return (0);
	init_texture_img(data);
	return (1);
}

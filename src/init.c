/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:47:31 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/06 13:05:10 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_texture_img_dino(t_data *data)
{
	data->texture.dino.idle[0].addr = mlx_get_data_addr
		(data->texture.dino.idle[0].img,
			&data->texture.dino.idle[0].bpp,
			&data->texture.dino.idle[0].line_len,
			&data->texture.dino.idle[0].endian);
	data->texture.dino.idle[1].addr = mlx_get_data_addr
		(data->texture.dino.idle[1].img,
			&data->texture.dino.idle[1].bpp,
			&data->texture.dino.idle[1].line_len,
			&data->texture.dino.idle[1].endian);
	data->texture.dino.runnin[0].addr = mlx_get_data_addr
		(data->texture.dino.runnin[0].img,
			&data->texture.dino.runnin[0].bpp,
			&data->texture.dino.runnin[0].line_len,
			&data->texture.dino.runnin[0].endian);
	data->texture.dino.runnin[1].addr = mlx_get_data_addr
		(data->texture.dino.runnin[1].img,
			&data->texture.dino.runnin[1].bpp,
			&data->texture.dino.runnin[1].line_len,
			&data->texture.dino.runnin[1].endian);
}

int	init_dino(t_data *data)
{
	data->texture.dino.idle[0].img = mlx_xpm_file_to_image(data->mlx,
			"sprite/DINO-IDLE-1.xpm", &data->texture.dino.idle[0].width,
			&data->texture.dino.idle[0].height);
	data->texture.dino.idle[1].img = mlx_xpm_file_to_image(data->mlx,
			"sprite/DINO-IDLE-2.xpm", &data->texture.dino.idle[1].width,
			&data->texture.dino.idle[1].height);
	data->texture.dino.runnin[0].img = mlx_xpm_file_to_image(data->mlx,
			"sprite/DINO-RUNNING-1.xpm", &data->texture.dino.runnin[0].width,
			&data->texture.dino.runnin[0].height);
	data->texture.dino.runnin[1].img = mlx_xpm_file_to_image(data->mlx,
			"sprite/DINO-RUNNING-2.xpm", &data->texture.dino.runnin[1].width,
			&data->texture.dino.runnin[1].height);
	if (!data->texture.dino.idle[0].img || !data->texture.dino.idle[1].img
		|| !data->texture.dino.runnin[0].img
		|| !data->texture.dino.runnin[1].img)
		return (0);
	init_texture_img_dino(data);
	return (1);
}

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
	data->texture.door.addr = mlx_get_data_addr(data->texture.door.img,
			&data->texture.door.bpp, &data->texture.door.line_len,
			&data->texture.door.endian);
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
	data->texture.door.img = mlx_xpm_file_to_image(data->mlx, "sprite/DOOR.xpm",
			&data->texture.door.width, &data->texture.door.height);
	if (!data->texture.north.img || !data->texture.south.img
		|| !data->texture.east.img || !data->texture.west.img)
		return (0);
	init_texture_img(data);
	if (!init_dino(data))
		return (0);
	return (1);
}

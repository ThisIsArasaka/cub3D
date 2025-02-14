/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:47:31 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/14 10:56:44 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_texture_img_dino(t_game *data)
{
	data->textures.dino.idle[0].addr = mlx_get_data_addr
		(data->textures.dino.idle[0].img,
			&data->textures.dino.idle[0].bpp,
			&data->textures.dino.idle[0].line_len,
			&data->textures.dino.idle[0].endian);
	data->textures.dino.idle[1].addr = mlx_get_data_addr
		(data->textures.dino.idle[1].img,
			&data->textures.dino.idle[1].bpp,
			&data->textures.dino.idle[1].line_len,
			&data->textures.dino.idle[1].endian);
	data->textures.dino.runnin[0].addr = mlx_get_data_addr
		(data->textures.dino.runnin[0].img,
			&data->textures.dino.runnin[0].bpp,
			&data->textures.dino.runnin[0].line_len,
			&data->textures.dino.runnin[0].endian);
	data->textures.dino.runnin[1].addr = mlx_get_data_addr
		(data->textures.dino.runnin[1].img,
			&data->textures.dino.runnin[1].bpp,
			&data->textures.dino.runnin[1].line_len,
			&data->textures.dino.runnin[1].endian);
}

int	init_dino(t_game *data)
{
	data->textures.dino.idle[0].img = mlx_xpm_file_to_image(data->mlx->mlx,
			"sprite/DINO-IDLE-1.xpm", &data->textures.dino.idle[0].width,
			&data->textures.dino.idle[0].height);
	data->textures.dino.idle[1].img = mlx_xpm_file_to_image(data->mlx->mlx,
			"sprite/DINO-IDLE-2.xpm", &data->textures.dino.idle[1].width,
			&data->textures.dino.idle[1].height);
	data->textures.dino.runnin[0].img = mlx_xpm_file_to_image(data->mlx->mlx,
			"sprite/DINO-RUNNING-1.xpm", &data->textures.dino.runnin[0].width,
			&data->textures.dino.runnin[0].height);
	data->textures.dino.runnin[1].img = mlx_xpm_file_to_image(data->mlx->mlx,
			"sprite/DINO-RUNNING-2.xpm", &data->textures.dino.runnin[1].width,
			&data->textures.dino.runnin[1].height);
	if (!data->textures.dino.idle[0].img || !data->textures.dino.idle[1].img
		|| !data->textures.dino.runnin[0].img
		|| !data->textures.dino.runnin[1].img)
		return (0);
	init_texture_img_dino(data);
	return (1);
}

void	init_texture_img(t_game *data)
{
	data->textures.north.addr = mlx_get_data_addr(data->textures.north.img,
			&data->textures.north.bpp, &data->textures.north.line_len,
			&data->textures.north.endian);
	data->textures.south.addr = mlx_get_data_addr(data->textures.south.img,
			&data->textures.south.bpp, &data->textures.south.line_len,
			&data->textures.south.endian);
	data->textures.east.addr = mlx_get_data_addr(data->textures.east.img,
			&data->textures.east.bpp, &data->textures.east.line_len,
			&data->textures.east.endian);
	data->textures.west.addr = mlx_get_data_addr(data->textures.west.img,
			&data->textures.west.bpp, &data->textures.west.line_len,
			&data->textures.west.endian);
	data->textures.door.addr = mlx_get_data_addr(data->textures.door.img,
			&data->textures.door.bpp, &data->textures.door.line_len,
			&data->textures.door.endian);
}

int	init_texture(t_game *data)
{
	data->textures.north.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->textures.north_wall, &data->textures.north.width,
			&data->textures.north.height);
	data->textures.south.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->textures.south_wall, &data->textures.south.width,
			&data->textures.south.height);
	data->textures.east.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->textures.east_wall, &data->textures.east.width,
			&data->textures.east.height);
	data->textures.west.img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->textures.west_wall, &data->textures.west.width,
			&data->textures.west.height);
	data->textures.door.img = mlx_xpm_file_to_image(data->mlx->mlx,
			"sprite/DOOR.xpm",
			&data->textures.door.width, &data->textures.door.height);
	if (!data->textures.north.img || !data->textures.south.img
		|| !data->textures.east.img || !data->textures.west.img
		|| !data->textures.door.img)
		return (0);
	init_texture_img(data);
	if (!init_dino(data))
		return (0);
	return (1);
}

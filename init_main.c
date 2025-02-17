/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:29:09 by michen            #+#    #+#             */
/*   Updated: 2025/02/17 12:02:09 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	draw(t_game *data)
{
	draw_floor(data);
	draw_ceiling(data);
	draw_walls(data);
	draw_dino(data);
	if (data->map->minimap)
		draw_map(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->windows,
		data->mlx->img.img, 0, 0);
	return (0);
}

void	init_dir(t_game *game)
{
	if (game->player->direction == 'N')
		game->player->dir = NORTH;
	if (game->player->direction == 'S')
		game->player->dir = SOUTH;
	if (game->player->direction == 'E')
		game->player->dir = EAST;
	if (game->player->direction == 'W')
		game->player->dir = WEST;
}

void	open_door(t_game *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(data->player->x + cos(data->player->dir));
	map_y = (int)(data->player->y + sin(data->player->dir));
	if (data->map->map[map_y][map_x] == '1')
		return ;
	if (data->map->map[map_y][map_x] == 'P')
		data->map->map[map_y][map_x] = 'O';
	else if (data->map->map[map_y][map_x] == 'O')
		data->map->map[map_y][map_x] = 'P';
}

void	init_var(t_game *game)
{
	game->map->map[(int)game->player->y][(int)game->player->x] = '0';
	game->textures.dino.state = 0;
	game->textures.dino.frame = 0;
	game->textures.dino.time = clock();
	game->player->x += 0.5;
	game->player->y += 0.5;
}

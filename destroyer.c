/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:27:57 by michen            #+#    #+#             */
/*   Updated: 2025/02/14 16:24:16 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"
#include "inc/cube3D.h"

void	free_game(t_texture *assets, t_game *game)
{
	if (assets)
	{
		free(assets->north_wall);
		free(assets->west_wall);
		free(assets->east_wall);
		free(assets->south_wall);
		free(assets->ceiling);
		free(assets->floor);
	}
	if (game->map)
	{
		free_tab(game->map->map);
		free(game->map);
	}
	if (game->player)
		free(game->player);
	if (game->mlx)
		free(game->mlx);	
}

void	free_list(t_list **node)
{
	t_list	*current;
	t_list	*next;

	current = *node;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	current = NULL;
}

int	mlx_destroy_textures(t_game *data)
{
	mlx_mouse_show(data->mlx->mlx, data->mlx->windows);
	if (data->textures.east.img)
		mlx_destroy_image(data->mlx->mlx, data->textures.east.img);
	if (data->textures.north.img)
		mlx_destroy_image(data->mlx->mlx, data->textures.north.img);
	if (data->textures.south.img)
		mlx_destroy_image(data->mlx->mlx, data->textures.south.img);
	if (data->textures.west.img)
		mlx_destroy_image(data->mlx->mlx, data->textures.west.img);
	if (data->textures.door.img)
		mlx_destroy_image(data->mlx->mlx, data->textures.door.img);
	if (data->textures.dino.idle[0].img)
		mlx_destroy_image(data->mlx->mlx, data->textures.dino.idle[0].img);
	if (data->textures.dino.idle[1].img)
		mlx_destroy_image(data->mlx->mlx, data->textures.dino.idle[1].img);
	if (data->textures.dino.runnin[0].img)
		mlx_destroy_image(data->mlx->mlx, data->textures.dino.runnin[0].img);
	if (data->textures.dino.runnin[1].img)
		mlx_destroy_image(data->mlx->mlx, data->textures.dino.runnin[1].img);
	if (data->mlx->img.img)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img.img);
	mlx_destroy_window(data->mlx->mlx, data->mlx->windows);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->mlx);
	return (free_game(&data->textures, data), exit(0), 0);
}

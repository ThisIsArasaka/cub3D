/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:46 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/14 14:26:21 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cube3D.h"
#include "inc/parsing.h"



int	move_hook(int keycode, t_game *data)
{
	if (keycode == XK_Escape)
		mlx_destroy_textures(data);
	if (keycode == XK_e)
		open_door(data);
	if (keycode == XK_w || keycode == XK_s)
	{
		data->textures.dino.state = 1;
		move_forward(data, keycode);
	}
	if (keycode == XK_a || keycode == XK_d)
	{
		data->textures.dino.state = 1;
		move_sideways(data, keycode);
	}
	if (keycode == XK_Left)
		data->player->dir -= ROT_SPEED;
	if (keycode == XK_Right)
		data->player->dir += ROT_SPEED;
	return (0);
}

int	mouse_hook(int x, int y, t_game *data)
{
	int	delta_x;

	(void)y;
	delta_x = x - WIDTH / 2;
	data->player->dir += delta_x * SENSITIVITY;
	mlx_mouse_move(data->mlx->mlx, data->mlx->windows, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	draw(t_game *data)
{
	draw_floor(data);
	draw_ceiling(data);
	draw_walls(data);
	draw_dino(data);
	if (data->map->minimap)
		draw_map(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->windows, data->mlx->img.img, 0, 0);
	return (0);
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

int	key_release(int keycode, t_game *data)
{
	if (keycode == XK_Tab)
		data->map->minimap = !data->map->minimap;
	data->textures.dino.state = 0;
	return (0);
}

void init_dir(t_game *game)
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

int	main(int ac, char **av)
{
	t_game game;

	
	if (!valid_args(ac, av)) // (1) && (2)
		return (0);
	if (valid_content(av[1], &game) && valid_textures(&game)) // (3)
	{
		get_player_pos(&game, game.map->map);
		printf("Game start\n");
	}
	else
		return (0);
	game.mlx->mlx = mlx_init();
	if (!game.mlx->mlx)
		return (free_game(&game.textures, &game), 0);
	game.map->map[(int)game.player->y][(int)game.player->x] = '0';
	game.textures.dino.state = 0;
	game.textures.dino.frame = 0;
	game.textures.dino.time = clock();
	
	game.player->x += 0.5;
	game.player->y += 0.5;
	init_dir(&game);
	game.mlx->windows = mlx_new_window(game.mlx->mlx, WIDTH, HEIGHT, "cube3D");
	if (!game.mlx->windows)
		return (free(game.mlx->mlx), free_game(&game.textures, &game), 0);
	
	game.mlx->img.img = mlx_new_image(game.mlx->mlx, WIDTH, HEIGHT);
	game.mlx->img.addr = mlx_get_data_addr(game.mlx->img.img, &game.mlx->img.bpp,
			&game.mlx->img.line_len, &game.mlx->img.endian);
	if (!init_texture(&game))
		return (mlx_destroy_textures(&game), 0);
	mlx_hook(game.mlx->windows, 17, (1L << 17), mlx_destroy_textures, &game);
	mlx_hook(game.mlx->windows, 2, (1L << 0), move_hook, &game);
	mlx_hook(game.mlx->windows, 6, (1L << 6), mouse_hook, &game);
	mlx_hook(game.mlx->windows, 3, (1L << 1), key_release, &game);
	mlx_loop_hook(game.mlx->mlx, draw, &game);
	// mlx_mouse_hide(game.mlx->mlx, game.mlx->windows);
	mlx_loop(game.mlx->mlx);
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:46 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/13 13:10:54 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cube3D.h"
#include "inc/parsing.h"

int	destroy(t_game *data)
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
	exit(0);
}

int	move_hook(int keycode, t_game *data)
{
	if (keycode == XK_Escape)
		destroy(data);
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
	printf("x: %f, y: %f, dir: %f\n", data->player->x, data->player->y,
		data->player->dir);
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

int	key_release(int keycode, t_game *data)
{
	if (keycode == XK_Tab)
		data->map->minimap = !data->map->minimap;
	data->textures.dino.state = 0;
	return (0);
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

	game.textures.dino.state = 0;
	game.textures.dino.frame = 0;
	game.textures.dino.time = clock();
	game.mlx->mlx = mlx_init();
	game.mlx->windows = mlx_new_window(game.mlx->mlx, WIDTH, HEIGHT, "cube3D");
	game.mlx->img.img = mlx_new_image(game.mlx->mlx, WIDTH, HEIGHT);
	game.mlx->img.addr = mlx_get_data_addr(game.mlx->img.img, &game.mlx->img.bpp,
			&game.mlx->img.line_len, &game.mlx->img.endian);
	if (!init_texture(&game))
		return (0);
	mlx_hook(game.mlx->windows, 17, (1L << 17), destroy, &game);
	mlx_hook(game.mlx->windows, 2, (1L << 0), move_hook, &game);
	mlx_hook(game.mlx->windows, 6, (1L << 6), mouse_hook, &game);
	mlx_hook(game.mlx->windows, 3, (1L << 1), key_release, &game);
	mlx_loop_hook(game.mlx->mlx, draw, &game);
	mlx_mouse_hide(game.mlx->mlx, game.mlx->windows);
	mlx_loop(game.mlx->mlx);
	
	return (0);
}

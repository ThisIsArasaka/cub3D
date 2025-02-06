/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:46 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/06 14:25:30 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	destroy(t_data *data)
{
	mlx_mouse_show(data->mlx, data->win);
	if (data->texture.east.img)
		mlx_destroy_image(data->mlx, data->texture.east.img);
	if (data->texture.north.img)
		mlx_destroy_image(data->mlx, data->texture.north.img);
	if (data->texture.south.img)
		mlx_destroy_image(data->mlx, data->texture.south.img);
	if (data->texture.west.img)
		mlx_destroy_image(data->mlx, data->texture.west.img);
	if (data->texture.door.img)
		mlx_destroy_image(data->mlx, data->texture.door.img);
	if (data->texture.dino.idle[0].img)
		mlx_destroy_image(data->mlx, data->texture.dino.idle[0].img);
	if (data->texture.dino.idle[1].img)
		mlx_destroy_image(data->mlx, data->texture.dino.idle[1].img);
	if (data->texture.dino.runnin[0].img)
		mlx_destroy_image(data->mlx, data->texture.dino.runnin[0].img);
	if (data->texture.dino.runnin[1].img)
		mlx_destroy_image(data->mlx, data->texture.dino.runnin[1].img);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	move_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroy(data);
	if (keycode == XK_e)
		open_door(data);
	if (keycode == XK_w || keycode == XK_s)
	{
		data->texture.dino.state = 1;
		move_forward(data, keycode);
	}
	if (keycode == XK_a || keycode == XK_d)
	{
		data->texture.dino.state = 1;
		move_sideways(data, keycode);
	}
	if (keycode == XK_Left)
		data->player.dir -= ROT_SPEED;
	if (keycode == XK_Right)
		data->player.dir += ROT_SPEED;
	printf("x: %f, y: %f, dir: %f\n", data->player.x, data->player.y,
		data->player.dir);
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	int	delta_x;

	(void)y;
	delta_x = x - WIDTH / 2;
	data->player.dir += delta_x * SENSITIVITY;
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	draw(t_data *data)
{
	draw_floor(data);
	draw_ceiling(data);
	draw_walls(data);
	draw_dino(data);
	if (data->map.minimap)
		draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_Tab)
		data->map.minimap = !data->map.minimap;
	data->texture.dino.state = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	char tmpmap[15][15] = {{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0',
								'0', '1', '0', '0', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0',
								'0', '1', '0', '0', '1'},
							{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0',
								'0', '1', '1', '1', '1'},
							{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '1', '1', 'P', '1', '1', '0', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0',
								'0', '0', '0', '0', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0',
								'0', '0', '0', '0', '1'},
							{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '1', '0', '0', '0', '0', '1', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '1', '1', '1', '1', '1', '1', '0', '0',
								'0', '0', '1', '0', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0',
								'0', '0', '0', '0', '1'},
							{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
								'1', '1', '1', '1', '1'}};
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			data.map.map[i][j] = tmpmap[i][j];
		}
	}
	data.player.x = 4;
	data.player.y = 4;
	data.player.dir = WEST;
	data.map.minimap = 0;
	data.map.width = 15;
	data.map.height = 15;
	data.map.floor_color = 0x00FF0FF0;
	data.map.ceiling_color = 0x00FFFF0F;
	data.texture.dino.state = 0;
	data.texture.dino.frame = 0;
	data.texture.dino.time = clock();
	if (argc == 2)
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cube3D");
		data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
				&data.img.line_len, &data.img.endian);
		if (!init_texture(&data))
			return (0);
		mlx_hook(data.win, 17, (1L << 17), destroy, &data);
		mlx_hook(data.win, 2, (1L << 0), move_hook, &data);
		mlx_hook(data.win, 6, (1L << 6), mouse_hook, &data);
		mlx_hook(data.win, 3, (1L << 1), key_release, &data);
		mlx_loop_hook(data.mlx, draw, &data);
		mlx_mouse_hide(data.mlx, data.win);
		mlx_loop(data.mlx);
	}
	else
		printf("Error\n");
	return (0);
}

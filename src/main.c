/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:46 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/03 09:14:52 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	destroy(t_data *data)
{
	if (data->texture.east.img)
		mlx_destroy_image(data->mlx, data->texture.east.img);
	if (data->texture.north.img)
		mlx_destroy_image(data->mlx, data->texture.north.img);
	if (data->texture.south.img)
		mlx_destroy_image(data->mlx, data->texture.south.img);
	if (data->texture.west.img)
		mlx_destroy_image(data->mlx, data->texture.west.img);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		destroy(data);
	if (keycode == XK_m)
		data->map.minimap = !data->map.minimap;
	if (keycode == XK_w || keycode == XK_s)
		move_forward(data, keycode);
	if (keycode == XK_a || keycode == XK_d)
		move_sideways(data, keycode);
	if (keycode == XK_Left)
		data->player.dir -= 0.1;
	if (keycode == XK_Right)
		data->player.dir += 0.1;
	printf("x: %f, y: %f, dir: %f\n", data->player.x, data->player.y,
		data->player.dir);
	return (0);
}

int	draw(t_data *data)
{
	draw_floor(data);
	draw_ceiling(data);
	draw_walls(data);
	if (data->map.minimap)
		draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	data.player.x = 4;
	data.player.y = 4;
	data.player.dir = WEST;
	data.map.minimap = 0;
	data.map.width = 15;
	data.map.height = 15;
	data.map.floor_color = 0x00FF0FF0;
	data.map.ceiling_color = 0x00FFFF0F;
	if (argc == 2)
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, 1920, 1080, "cube3D");
		data.img.img = mlx_new_image(data.mlx, 1920, 1080);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
				&data.img.line_len, &data.img.endian);
		if (!init_texture(&data))
			return (0);
		mlx_hook(data.win, 17, (1L << 17), destroy, &data);
		mlx_hook(data.win, 2, (1L << 0), key_hook, &data);
		// mlx_mouse_hook(data.win, mouse_hook, &data);
		mlx_loop_hook(data.mlx, draw, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Error\n");
	return (0);
}

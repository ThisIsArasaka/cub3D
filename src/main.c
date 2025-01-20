/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:46 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/20 11:34:41 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		destroy(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	(void)argv;
	if (argc == 2)
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, 1920, 1080, "cube3D");
		data.img.img = mlx_new_image(data.mlx, 1920, 1080);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
				&data.img.line_len, &data.img.endian);
		mlx_hook(data.win, 17, (1L << 17), destroy, &data);
		mlx_hook(data.win, 2, (1L << 0), key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
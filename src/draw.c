/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:02:02 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/21 09:49:55 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1920)
	{
		y = 1080 / 2;
		while (y < 1080)
		{
			my_mlx_pixel_put(&data->img, x, y, 0x0000FF00);
			y++;
		}
		x++;
	}
}

void	draw_ceiling(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080 / 2)
		{
			my_mlx_pixel_put(&data->img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}
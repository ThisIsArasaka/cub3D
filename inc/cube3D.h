/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:37:18 by olardeux          #+#    #+#             */
/*   Updated: 2025/01/23 19:36:13 by olardeux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define PI 3.14159265358979323846

typedef struct s_map
{
	int			**map;
	int			floor_color;
	int			ceiling_color;
}				t_map;

typedef struct s_ray
{
	double		ray_angle;
	double		ray_dirx;
	double		ray_diry;
	double		stepx;
	double		stepy;
	double		distx;
	double		disty;
}				t_ray;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
	double		plane;
}				t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		ray;
}				t_data;

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_floor(t_data *data);
void			draw_ceiling(t_data *data);
void			draw_walls(t_data *data);
void			draw_minimap(t_data *data);

#endif
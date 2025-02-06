/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olardeux <olardeux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:37:18 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/06 13:03:06 by olardeux         ###   ########.fr       */
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

# define HEIGHT 540
# define WIDTH 960

# define MINIMAP_SIZE 10

# define PI 3.14159265358979323846
# define FOV PI / 3

# define SPEED 0.1
# define ROT_SPEED 0.31 / 2
# define SENSITIVITY 0.005
# define MARGIN 0.5

# define SOUTH PI / 2
# define NORTH 3 * PI / 2
# define EAST 0
# define WEST PI

typedef struct s_map
{
	char		map[15][15];
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
	int			minimap;
}				t_map;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	double		ray_angle;
	double		ray_dirx;
	double		ray_diry;
	double		stepx;
	double		stepy;
	double		distx;
	double		disty;
	double		delta_distx;
	double		delta_disty;
	double		wall_dist;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		color;
	double	wall_x;
	int		texture_x;
	int		texture_y;
	double	step;
	double	tex_pos;
}				t_ray;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
}				t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_dino
{
	int 		state;
	int 		frame;
	clock_t		time;
	t_img		idle[2];
	t_img		runnin[2];
}				t_dino;

typedef struct s_texture
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_img		door;
	t_dino		dino;
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_texture	texture;
}				t_data;

void			draw_floor(t_data *data);
void			draw_ceiling(t_data *data);
void			draw_walls(t_data *data);
void			draw_map(t_data *data);
void			draw_dino(t_data *data);

void			dda(t_data *data, int x);
void			init_dda(t_data *data);
void			dda_loop(t_data *data, int *side, int *door);

void 			put_wall_pixel(t_data *data, int x, int side, int door);

void			move_forward(t_data *data, int keycode);
void			move_sideways(t_data *data, int keycode);
void			open_door(t_data *data);

int				init_texture(t_data *data);

int				create_trgb(int t, int r, int g, int b);
int				get_pixel_color(t_img *img, int x, int y);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:37:18 by olardeux          #+#    #+#             */
/*   Updated: 2025/02/13 12:02:30 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

#include "parsing.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <lib/mlx/mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define HEIGHT 540
# define WIDTH 960

# define MINIMAP_SIZE 15

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

# define MINIMAP_COLOR_WALL 0x0028B463
# define MINIMAP_COLOR_FLOOR 0x00C0392B 
# define MINIMAP_COLOR_PLAYER 0x00273746 
# define MINIMAP_COLOR_DOOR 0x00FFD700



void			draw_floor(t_game *data);
void			draw_ceiling(t_game *data);
void			draw_walls(t_game *data);
void			draw_map(t_game *data);
void			draw_dino(t_game *data);

void			dda(t_game *data, int x);
void			init_dda(t_game *data);
void			dda_loop(t_game *data, int *side, int *door);

void			put_wall_pixel(t_game *data, int x, int side, int door);

void			move_forward(t_game *data, int keycode);
void			move_sideways(t_game *data, int keycode);
void			open_door(t_game *data);

int				init_texture(t_game *data);

int				create_trgb(int t, int r, int g, int b);
int				get_pixel_color(t_img *img, int x, int y);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
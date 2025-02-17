/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:42:20 by michen            #+#    #+#             */
/*   Updated: 2025/02/17 12:02:27 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "lib/libft/gnl/get_next_line.h"
# include "lib/libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KO 0
# define OK 1

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
	double		wall_dist_corrected;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	int			color;
	double		wall_x;
	int			texture_x;
	int			texture_y;
	double		step;
	double		tex_pos;
}				t_ray;

typedef struct s_map
{
	char		**map;
	int			max_width;
	int			max_height;
	int			minimap;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir;
	double		new_x;
	double		new_y;
	double		check_x;
	double		check_y;
	char		direction;
}				t_player;

typedef struct s_mlx
{
	void		*mlx;
	t_img		img;
	void		*windows;
}				t_mlx;

typedef struct s_gnlassets
{
	int			fd;
	int			readed_time;
	int			filled;
}				t_gnlassets;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct s_minimap
{
	int			is_active;
	int			arrow_x;
	int			arrow_y;
	double		angle;
}				t_minimap;

typedef struct s_dino
{
	int			state;
	int			frame;
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

	void		*north_wall;
	void		*west_wall;
	void		*east_wall;
	void		*south_wall;

	t_img		door;
	t_dino		dino;

	t_color		*floor;
	t_color		*ceiling;
}				t_texture;

typedef struct s_game
{
	t_player	*player;
	t_map		*map;
	t_texture	textures;
	t_mlx		*mlx;

	t_ray		ray;
}				t_game;

/*-- UTILS -----------------------------------------*/
char			*fill_with_space(char *s, int len);
int				longest_str(char **tab);
int				skip_space(char *str, int actual_pos);
int				list_len(t_list *map);
char			**list_to_tab(t_list *map);

int				init_g(t_game *g);
int				find_number(char *s, int start);
void			print_tab(char **tab);
char			*format(char *s);

void			get_player_pos(t_game *g, char **map);
void			free_tab(char **tab);
void			free_config(t_game *g);

void			print_list(t_list *lst);
int				last_char(char c, char *s);
int				tab_len(char **tab);
int				is_player(char c);
int				find_zero(char *s);

int				near_void(char **map, int x, int y);
int				first_nb_pos(char *s);
int				forbidden_char(char c);
int				is_sep(char c);
int				set_color(char *s, int color);

/*-- PARSING ---------------------------------------*/
int				valid_args(int ac, char **av);
int				valid_extension(char *str);

/*-- INIT ------------------------------------------*/
int				direction_textures(char *str, t_game *g);
int				valid_content(char *map_file, t_game *g);
int				valid_textures(t_game *g);

/*-- MAP CHECK -------------------------------------*/
// int						valid_map_file(char *map);
void			map(t_game *g, t_gnlassets *gnl, char *line);
int				valid_map(t_game *g);
int				is_player(char c);
int				closed_map(char **map);

/*-- DESTROYER -------------------------------------*/
void			free_list(t_list **node);
int				mlx_destroy_textures(t_game *data);
void			free_game(t_texture *assets, t_game *game);

/*-- INIT MAIN -------------------------------------*/
int				draw(t_game *data);
void			init_dir(t_game *game);
void			open_door(t_game *data);
void			init_var(t_game *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:42:20 by michen            #+#    #+#             */
/*   Updated: 2025/02/13 10:40:04 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "lib/libft/gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KO 0
# define OK 1

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct s_textures
{
	void		*north_wall;
	void		*west_wall;
	void		*east_wall;
	void		*south_wall;

	t_color		*floor;
	t_color		*ceiling;
}				t_textures;

typedef struct s_map
{
	char		**map;
	int			max_width;
	int			max_height;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	char		direction;
}				t_player;

typedef struct s_mlx
{
	void		*ptr;
	void		*windows;
}				t_mlx;

typedef struct s_gnlassets
{
	int			fd;
	int			readed_time;
	int			filled;
}				t_gnlassets;

typedef struct s_game
{
	t_player	*player;
	t_map		*map;
	t_textures	*textures;
	t_mlx		*mlx;
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

/*-- DESTROYER -------------------------------------*/
void			free_list(t_list **node);

#endif

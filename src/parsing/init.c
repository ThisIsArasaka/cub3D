/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:54:07 by michen            #+#    #+#             */
/*   Updated: 2025/02/14 13:47:23 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		is_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c == ',')
		return (2);
	return (0);
}

int		set_color(char *s, int color)
{
	int		i;
	int		cursor;
	int		color_code;
	char	*nb;

	i = skip_space(s, 0);
	i++;
	i = skip_space(s, i);
	cursor = 0;
	while (s[i] && cursor != color)
	{
		if (cursor == color)
			break ;
		cursor++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (s[i] == ',')
			i++;
		if (!ft_isdigit(s[i]) && is_sep(s[i]))
			return (printf("ERRRR\n"), -1);
	}
	if (s[i] && s[i] == ',')
		i++;
	printf("collect : %s\n", s + i);
	if (!find_number(s, i))
		return (-1);
	nb = ft_substr(s, i, find_number(s, i));
	color_code = ft_atoi(nb);
	free(nb);
	printf("color:%d\n", color_code);
	return (color_code);
}
// RECHECK CA
int		env_color(char *s, t_game *game)
{
	int		i;

	i = skip_space(s, 0);
	if (!ft_strncmp("C ", s + i, 2) || !ft_strncmp("C\t", s + i, 2))
	{
		game->textures.ceiling->red = set_color(s, 0);
		game->textures.ceiling->green = set_color(s, 1);
		game->textures.ceiling->blue = set_color(s, 2);
		return (1);
	}
	else if (!ft_strncmp("F ", s + i, 2) || !ft_strncmp("F\t", s + i, 2))
	{
		game->textures.floor->red = set_color(s, 0);
		game->textures.floor->green = set_color(s, 1);
		game->textures.floor->blue = set_color(s, 2);
		return (1);
	}
	return (0);
}

int		filled_texture(char *dir, char *str, int i, t_game *g)
{
	char	*space;
	char	*tab;

	tab = ft_strjoin(dir, "\t");
	space = ft_strjoin(dir, " ");
	if (!ft_strncmp(str + i, tab, 3) || !ft_strncmp(str + i, space, 3))
	{
		if (!ft_strncmp("NO", dir, 2) && !g->textures.north_wall)
			return (free(tab), free(space), 0);
		if (!ft_strncmp("SO", dir, 2) && !g->textures.south_wall)
			return (free(tab), free(space), 0);
		if (!ft_strncmp("WE", dir, 2) && !g->textures.west_wall)
			return (free(tab), free(space), 0);
		if (!ft_strncmp("EA", dir, 2) && !g->textures.east_wall)
			return (free(tab), free(space), 0);
	}
	free(tab);
	free(space);
	return (1);
}

int		direction_textures(char *str, t_game *g)
{
	int		i;
	int		next_word;

	i = skip_space(str, 0);
	next_word = skip_space(str, i + 2);
	if (!ft_strncmp(str + i, "NO", 2) && !filled_texture("NO", str, i, g))
		g->textures.north_wall = ft_substr(str, next_word, ft_strlen(str));
	else if (!ft_strncmp(str + i, "SO", 2) && !filled_texture("SO", str, i, g))
		g->textures.south_wall = ft_substr(str, next_word, ft_strlen(str));
	else if (!ft_strncmp(str + i, "WE", 2) && !filled_texture("WE", str, i, g))
		g->textures.west_wall = ft_substr(str, next_word, ft_strlen(str));
	else if (!ft_strncmp(str + i, "EA", 2) && !filled_texture("EA", str, i, g))
		g->textures.east_wall = ft_substr(str, next_word, ft_strlen(str));
	else if (env_color(str, g))
		return (free(str), 1);
	else
		return (free(str), 0);
	return (free(str), 1);
}

int		valid_content(char *map_file, t_game *g)
{
	t_gnlassets		gnl;
	char	*line;

	init_g(g);
	gnl.readed_time = 0;
	gnl.filled = 0;
	gnl.fd = open (map_file, O_RDONLY);
	if (gnl.fd == -1)
	{
		printf("Error\n Cannot open file \"%s\"\n", map_file);
		return (0);
	}
	line = get_next_line(gnl.fd);
	while (line)
	{
		gnl.readed_time++;
		if (gnl.filled < 6)
			gnl.filled += direction_textures(line, g);
		else
		{
			map(g, &gnl, line);
			if (!valid_map(g))
				return (close(gnl.fd), 0);
			break ;
		}
		line = get_next_line(gnl.fd);
	}
	if (gnl.filled < 6)
		printf("Error\n There is textures missing\n");
	close(gnl.fd);
	return (1);
}

// Ce qui manque : Mettre le chemin dans le truc
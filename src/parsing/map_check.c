/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:18:19 by michen            #+#    #+#             */
/*   Updated: 2025/02/17 10:52:42 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	closed_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (find_zero(map[y]))
		return (printf("Error\nMap not closed\n"), 0);
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_player(map[y][x]) || map[y][x] == 'P')
			{
				if (!near_void(map, x, y))
					x++;
				else
					return (printf("Error\nMap not closed\n"), 0);
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	if (find_zero(map[y - 1]))
		return (printf("Error\nMap not closed\n"), 0);
	return (1);

}

int	player_exist(char **map)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_player(map[y][x]))
				player++;
			x++;
		}
		y++;
		x = 0;
	}
	if (player != 1)
		return (0);
	return (1);
}

int	valid_map(t_game *g)
{
	int	x;
	int	y;

	if (!g->map->map)
		return (printf("Error\nmap is missing\n"), 0);
	x = 0;
	y = 0;
	while (g->map->map[y])
	{
		while (g->map->map[y][x])
		{
			if (forbidden_char(g->map->map[y][x]))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	g->map->max_height = y;
	g->map->max_width = ft_strlen(g->map->map[0]);
	if (!closed_map(g->map->map) || !player_exist(g->map->map))
		return (printf("Error\nmap invalid\n"), 0);
	return (1);
}

void	map_convert(t_list *map, t_game *g)
{
	int	i;
	int	max;

	i = 0;
	if (!map)
		return ;
	g->map->map = list_to_tab(map);
	max = longest_str(g->map->map);
	while (g->map->map[i])
	{
		if (!last_char('\n', g->map->map[i]))
			g->map->map[i] = fill_with_space(g->map->map[i], max);
		i++;
	}
	free_list(&map);
}

void	skip_blank(char *str, t_list **map, int fd)
{
	char	*line;

	free(str);
	line = get_next_line(fd);
	while (line && !ft_strncmp("\n\0", line, 2))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		*map = ft_lstnew(format(line));
}

void	map(t_game *g, t_gnlassets *gnl, char *str)
{
	char	*line;
	t_list	*map;

	map = NULL;
	if (!str)
		return ;
	if (str && str[0] == '\n')
	{
		skip_blank(str, &map, gnl->fd);
	}
	else
		map = ft_lstnew(format(str));
	line = get_next_line(gnl->fd);
	while (line)
	{
		if (line)
			ft_lstadd_back(&map, ft_lstnew(format(line)));
		gnl->readed_time++;
		line = get_next_line(gnl->fd);
	}
	if (!map)
		return ;
	map_convert(map, g);
}
// REVOIR SI SEGGFAULT
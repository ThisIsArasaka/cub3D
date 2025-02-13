/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:18:19 by michen            #+#    #+#             */
/*   Updated: 2025/02/13 11:51:45 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// int		valid_map_file(char *map)
// {
// 	int		fd;
// 	t_game	*game;
// 	char	**tab;

// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 		return (printf("Error : Cant open map file\n"), 0);
	
// 	get_next_line(fd);
// 	/*Check si la map est fermee
// 	Check dans une autre fct si les textures existent
// 	Check si il y a xxx,xxx,xxx pour le RGB
// 	check presence de NO WE EA SO | C(celling) F(floor)
// 	verifier si les textures existent

// 	exemple de map valide :
// 	11111111 111111
// 	100000001000001
// 	11101111111111
// 	11111
// 	*/
// 	return (1);
// }

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("list:%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int		last_char(char c, char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i + 1])
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

int		tab_len(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

int		near_void(char **map, int x, int y)
{
	int		max_x;
	int		max_y;
	
	max_x = ft_strlen(map[0]);
	max_y = tab_len(map);
	if ((x >= 1 && x < max_x) && (y >= 1 && y < max_y - 1))
	{
		if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
			return (1);
		if (map[y][x - 1] == '\0' || map[y][x + 1] == '\0')
			return (1);
		if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
			return (1);
		if (map[y - 1][x] == '\0' || map[y + 1][x] == '\0')
			return (1);
	}
	return (0);
}

int		is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int		find_zero(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '0')
			return (1);
		x++;
	}
	return (0);
}

int		closed_map(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_player(map[y][x]) || map[y][x] == 'P')
			{
				if (!near_void(map, x, y))
					x++;
				else
					return (printf("Error : Map not closed\n"), 0);
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	if (find_zero(map[y - 1]))
		return (printf("Error : Map not closed\n"), 0);
	return (1);
}

int		forbidden_char(char c)
{
	if (is_player(c) || c == ' ' || c == 'P' || c == '1' || c == '0')
		return (0);
	printf("Error, Forbidden char found\n");
	return (1);
}

int		player_exist(char **map)
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

int		valid_map(t_game *g)
{
	int	x;
	int	y;

	if (!g->map->map)
		return (printf("Error, map is missing\n"), 0);
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
		return (printf("Error, map invalid\n"), 0);
	return (1);
}

void	map(t_game *g, t_gnlassets *gnl, char *str)
{
	char	*line;
	t_list	*map;
	int		max;
	int		i;

	i = 0;
	map = NULL;
	if (!str)
		return ;
	if (str && str[0] == '\n')
	{
		line = get_next_line(gnl->fd);
		while (line && !ft_strncmp("\n\0", line, 2))
			line = get_next_line(gnl->fd);
		if (line)
		{
			map = ft_lstnew(format(line));
		}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:12:59 by michen            #+#    #+#             */
/*   Updated: 2025/02/14 17:27:43 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_extension(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '.')
		i++;
	if (ft_strncmp(str + i, ".cub", 5))
		return (0);
	return (1);
}

int	valid_args(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Invalid number of args\n");
		printf("Usage : ./cub3d <map_name.cub>\n");
		return (0);
	}
	if (!valid_extension(av[1]))
	{
		printf("Invalid extension, needed file : <map.cub>\n");
		return (0);
	}
	return (1);
}

void	get_player_pos(t_game *g, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_player(map[y][x]))
			{
				g->player->direction = map[y][x];
				g->player->x = x;
				g->player->y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

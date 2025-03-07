/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:01 by michen            #+#    #+#             */
/*   Updated: 2025/02/17 11:22:31 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	init_g2(t_game *g)
{
	if (!g->player || !g->map || !g->mlx || !g->textures.ceiling
		|| !g->textures.floor)
	{
		free_config(g);
		return (0);
	}
	return (1);
}

int	init_g(t_game *g)
{
	g->player = ft_calloc(sizeof(t_player), 1);
	g->map = ft_calloc(sizeof(t_map), 1);
	g->mlx = ft_calloc(sizeof(t_mlx), 1);
	g->textures.ceiling = ft_calloc(sizeof(t_color), 1);
	g->textures.floor = ft_calloc(sizeof(t_color), 1);
	if (!init_g2(g))
		return (0);
	g->player->direction = 0;
	g->player->x = 0;
	g->player->y = 0;
	g->map->map = NULL;
	g->mlx->mlx = NULL;
	g->mlx->windows = NULL;
	g->textures.ceiling->red = -1;
	g->textures.ceiling->green = -1;
	g->textures.ceiling->blue = -1;
	g->textures.floor->red = -1;
	g->textures.floor->green = -1;
	g->textures.floor->blue = -1;
	g->textures.north_wall = NULL;
	g->textures.south_wall = NULL;
	g->textures.west_wall = NULL;
	g->textures.east_wall = NULL;
	return (1);
}

int	find_number(char *s, int start)
{
	int	i;

	i = start;
	while (ft_isdigit(s[i]))
		i++;
	return (i - start);
}

int	compare_dir(char *s, int start, char *dir)
{
	int		i;
	char	*space;
	char	*tab;

	tab = ft_strjoin(dir, "\t");
	space = ft_strjoin(dir, " ");
	if (!tab || !space)
		return (0);
	i = start;
	if (!ft_strncmp(s + i, space, 3) || !ft_strncmp(s + i, tab, 3))
	{
		free(tab);
		free(space);
		return (1);
	}
	free(tab);
	free(space);
	return (0);
}

void	print_tab(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		printf("str[%d]:%s\n", j, tab[j]);
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:32:35 by michen            #+#    #+#             */
/*   Updated: 2025/02/14 13:20:43 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*format(char *s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	str = ft_calloc(sizeof(char), len + 1);
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && i != len - 1)
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] && s[i] != '\n')
		str[i] = s[i];
	free(s);
	return (str);
}

int	valid_nb(t_color *element)
{
	if (element->blue >= 0 && element->blue <= 255)
	{
		if (element->red >= 0 && element->red <= 255)
		{
			if (element->green >= 0 && element->green <= 255)
				return (1);
		}
	}
	return (0);
}

int	check_textures(t_game *g)
{
	if (!g->textures.north_wall || !g->textures.south_wall)
		return (0);
	if (!g->textures.east_wall || !g->textures.west_wall)
		return (0);
	return (1);
}

int	valid_textures(t_game *g)
{
	if (!g)
		return (0);
	if (g->textures.north_wall)
		g->textures.north_wall = format(g->textures.north_wall);
	if (g->textures.south_wall)
		g->textures.south_wall = format(g->textures.south_wall);
	if (g->textures.east_wall)
		g->textures.east_wall = format(g->textures.east_wall);
	if (g->textures.west_wall)
		g->textures.west_wall = format(g->textures.west_wall);
	if (valid_nb(g->textures.ceiling) && valid_nb(g->textures.floor))
	{
		if (check_textures(g))
		{
			if (g->map->map)
				return (1);
			else
				return (printf("Error\nNo map\n"), 0);
		}
	}
	return (printf("Error\nInvalid content in \".cub\" file\n"), 0);
}

// Verifier toutes les data recuperee dans le .cub
// Changer les path en textures
// Verifier si les couleurs sont dans la bonne range (0->255)
// Verifier la map (Pas sur ici)
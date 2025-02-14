/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:47:33 by michen            #+#    #+#             */
/*   Updated: 2025/02/14 17:27:29 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	forbidden_char(char c)
{
	if (is_player(c) || c == ' ' || c == 'P' || c == '1' || c == '0')
		return (0);
	printf("Error\nForbidden char found\n");
	return (1);
}

int	near_void(char **map, int x, int y)
{
	int	max_x;
	int	max_y;

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

int	is_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c == ',')
		return (2);
	return (0);
}

int	first_nb_pos(char *s)
{
	int	i;

	i = skip_space(s, 0);
	i++;
	i = skip_space(s, i);
	return (i);
}

int	set_color(char *s, int color)
{
	int		i;
	int		cursor;
	int		color_code;
	char	*nb;

	i = first_nb_pos(s);
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
			return (-1);
	}
	if (!find_number(s, i))
		return (-1);
	nb = ft_substr(s, i, find_number(s, i));
	color_code = ft_atoi(nb);
	free(nb);
	return (color_code);
}

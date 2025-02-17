/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:17:12 by michen            #+#    #+#             */
/*   Updated: 2025/02/17 11:18:00 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	closed_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!find_zero(map[y]))
		return (0);
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_player(map[y][x]) || map[y][x] == 'P')
			{
				if (!near_void(map, x, y))
					x++;
				else
					return (0);
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	return (find_zero(map[y - 1]));
}

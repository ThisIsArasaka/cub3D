/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:55 by michen            #+#    #+#             */
/*   Updated: 2025/02/13 10:37:20 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

void	get_player_pos(t_game *g, char **map)
{
	int	x;
	int y;

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
int	main(int ac, char **av)
{
	t_game game;

	if (!valid_args(ac, av)) // (1) && (2)
		return (0);
	if (valid_content(av[1], &game) && valid_textures(&game)) // (3)
	{
		get_player_pos(&game, game.map->map);
		printf("Game start\n");
	}
	// printf("%c\n", game.player->direction);
	// if (!valid_map_file(av[1])) // (4)
		// return (0);

	// init_game(game, av);
}

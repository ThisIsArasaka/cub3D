/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:27:57 by michen            #+#    #+#             */
/*   Updated: 2025/02/11 14:05:30 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	free_game(t_textures *assets, t_game *game)
// {
// 	free(assets->north_wall);
// 	free(assets->west_wall);
// 	free(assets->east_wall);
// 	free(assets->south_wall);
	
// }

void	free_list(t_list **node)
{
	t_list	*current;
	t_list	*next;

	current = *node;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	current = NULL;
}

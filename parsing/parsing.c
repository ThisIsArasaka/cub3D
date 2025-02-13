/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:12:59 by michen            #+#    #+#             */
/*   Updated: 2025/02/04 16:14:53 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_extension(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '.')
		i++;
	if (ft_strncmp(str + i, ".cub", 5))
		return (0);
	return (1);
}

int		valid_args(int ac, char **av)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:27:21 by michen            #+#    #+#             */
/*   Updated: 2025/02/14 17:00:57 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	list_len(t_list *map)
{
	int	len;

	len = 1;
	if (!map)
		return (0);
	while (map->next != NULL)
	{
		len++;
		map = map->next;
	}
	return (len);
}

char	**list_to_tab(t_list *map)
{
	char	**tab;
	int		x;

	if (!map || !map->content)
		return (NULL);
	tab = ft_calloc(sizeof(char *), list_len(map) + 1);
	x = 0;
	while (map != NULL)
	{
		tab[x] = ft_strdup(map->content);
		x++;
		map = map->next;
	}
	return (tab);
}

int	skip_space(char *str, int actual_pos)
{
	int	i;

	i = actual_pos;
	if (!str || (size_t)i > ft_strlen(str))
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

char	*fill_with_space(char *s, int len)
{
	int		i;
	char	*str;

	str = ft_calloc(sizeof(char), len + 1);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	free(s);
	return (str);
}

int	longest_str(char **tab)
{
	int	max;
	int	x;

	max = 0;
	x = 0;
	while (tab[x])
	{
		if (ft_strlen(tab[x]) > (size_t)max)
			max = ft_strlen(tab[x]);
		x++;
	}
	return (max);
}

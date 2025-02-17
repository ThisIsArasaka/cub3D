/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:47:35 by michen            #+#    #+#             */
/*   Updated: 2025/02/17 12:17:25 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("list:%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	last_char(char c, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i + 1])
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	find_zero(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '0' || is_player(s[x]) || s[x] == 'P')
			return (0);
		x++;
	}
	return (1);
}

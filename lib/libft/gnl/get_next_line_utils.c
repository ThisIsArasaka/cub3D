/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:38:29 by michen            #+#    #+#             */
/*   Updated: 2025/02/01 15:52:14 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strjoin_(char *s1, char *s2)
{
	char	*temp;
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen_(s1);
	len_2 = ft_strlen_(s2);
	temp = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!temp)
		return (free(s1), NULL);
	ft_strlcpy_(temp, s1, len_1 + 1);
	ft_strlcpy_(temp + len_1, s2, len_2 + 1);
	free(s1);
	return (temp);
}

size_t	ft_strlcpy_(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < size)
		*dest = '\0';
	while (*src++)
		++i;
	return (i);
}

size_t	ft_strlen_(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_snipe(char *str, char target)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == target)
			return (i);
		else
			i++;
	}
	return (-1);
}

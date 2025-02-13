/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:08:18 by michen            #+#    #+#             */
/*   Updated: 2023/11/28 17:37:03 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	feat_checkch(char c, char const *trig)
{
	int	i;

	i = 0;
	while (trig[i])
	{
		if (c == trig[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	l;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s1) - 1;
	while (s1[i] && feat_checkch(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_calloc(1, 1));
	while (feat_checkch(s1[l], set))
		l--;
	return (ft_substr(s1, i, l - i + 1));
}

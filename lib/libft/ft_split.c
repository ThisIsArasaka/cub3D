/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:04:36 by michen            #+#    #+#             */
/*   Updated: 2023/12/05 16:01:48 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep(char c, char set)
{
	if (c == set || c == '\0')
		return (1);
	return (0);
}

static int	countword(const char *str, char set)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (sep(str[i + 1], set) && !sep(str[i], set))
			word++;
		i++;
	}
	return (word);
}

int	split_string(const char *s, char c, char **res, int *j)
{
	int	k;
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		k = 0;
		while (s[i + k] != '\0' && s[i + k] != c)
			k++;
		res[*j] = ft_substr(s, i, k);
		if (!res[*j])
			return (1);
		(*j)++;
		i += k;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		j;
	char	**res;

	if (s == NULL)
		return (NULL);
	j = 0;
	res = (char **)malloc((countword(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	if (split_string(s, c, res, &j))
		return (NULL);
	res[j] = NULL;
	return (res);
}

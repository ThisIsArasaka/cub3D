/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:52 by michen            #+#    #+#             */
/*   Updated: 2023/11/15 19:13:20 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1p;
	unsigned const char	*s2p;
	size_t				i;

	s1p = (unsigned const char *)s1;
	s2p = (unsigned const char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n)
	{
		if ((s1p[i] == s2p[i]) && (i == n))
			break ;
		if (s1p[i] != s2p[i])
			return (s1p[i] - s2p[i]);
		i++;
	}
	return ((int)(s1p[i] - s2p[i]));
}
/*
#include <string.h>

int	main(void)
{
	char	str1[] = {128, 0, 127, 0};
	char	str2[] = {128, 0, 127, 0};
	int		result;

	result = ft_memcmp(str1, str2, 4);
	if (result < 0)
	{
		printf("str1 est inférieur à str2\n");
	}
	if (result > 0)
	{
		printf("str1 est supérieur à str2\n");
	}
	if (result == 0)
	{
		printf("str1 est identique à str2\n");
	}
	printf("%d", result);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:23:29 by michen            #+#    #+#             */
/*   Updated: 2023/11/20 22:21:50 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < n - 1) && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <string.h>

int	main(void)
{
	const char	*str1 = "Test\200";
	const char	*str2 = "Test\0";
	int			result;

	result = ft_strncmp(str1, str2, 6);
	if (result < 0)
	{
		printf("str1 is less than str2\n");
	}
	else if (result > 0)
	{
		printf("str2 is less than str1\n");
	}
	else
	{
		printf("str1 is equal to str2\n");
	}
	printf("%d", result);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:55:09 by michen            #+#    #+#             */
/*   Updated: 2023/11/28 17:30:06 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (dst == NULL && size == 0)
		return (0);
	i = 0;
	while (src[i])
		i++;
	j = i;
	i = 0;
	while (dst[i] && i < size)
		i++;
	k = i;
	while ((src[i - k] && i + 1 < size))
	{
		dst[i] = src[i - k];
		i++;
	}
	if (k < size)
		dst[i] = '\0';
	return (k + j);
}
/*int	main(void)
{
	char	dest[] = "Hello";
	char	src[] = " World";
	size_t	size;

	size = 0;
	printf("Before: %s\n", dest);
	printf("After: %zu\n", ft_strlcat(dest, src, size));
	return (0);
}
*/
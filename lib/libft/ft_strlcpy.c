/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:30:49 by michen            #+#    #+#             */
/*   Updated: 2023/11/22 16:34:13 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		++i;
	}
	if (i < size)
		*dest = 0;
	while (*src++)
		++i;
	return (i);
}
/*
#include <bsd/string.h>

int	main(void)
{
	char src[] = "Bonjour, monde!";
	char dst[100];
	size_t size = sizeof(dst);

	ft_strlcpy(dst, src, size);

	printf("Chaîne copiée : %s%zu\n", dst, size);
	return (0);
}*/

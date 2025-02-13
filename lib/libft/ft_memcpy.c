/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:47:25 by michen            #+#    #+#             */
/*   Updated: 2023/11/28 17:24:24 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	const char		*srcptr;
	char			*destptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	destptr = (char *)dest;
	srcptr = (const char *)src;
	i = 0;
	while (i < n)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return (destptr);
}
/*
int	main(void) {
	char src[20] = "Hello, World!";
	char dest[20];

	printf("Before memcpy:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);

	ft_memcpy(dest, src, 3);

	printf("After memcpy:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);

	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michen <michen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:19:53 by michen            #+#    #+#             */
/*   Updated: 2023/11/28 17:28:15 by michen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destptr;
	const unsigned char	*srcptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	srcptr = (const unsigned char *)src;
	destptr = (unsigned char *)dest;
	i = 0;
	if (destptr < srcptr)
	{
		while (i < n)
		{
			destptr[i] = srcptr[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			destptr[i] = srcptr[i];
	}
	return (destptr);
}
/*int	main(void)
{
	char	str[20] = "Hello, iWorld!";

	printf("Before memmove: %s\n", str);
	ft_memmove(str + 7, str, 7);
	printf("After memmove: %s\n", str);
	return (0);
}
*/